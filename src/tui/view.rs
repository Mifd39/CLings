use ratatui::{
    layout::{Alignment, Constraint, Direction, Layout, Rect},
    style::{Color, Modifier, Style},
    text::{Line, Span},
    widgets::{Block, Borders, Clear, List, ListItem, Paragraph, Wrap},
    Frame,
};
use crate::tui::model::{App, SelectionMode};

pub fn ui(f: &mut Frame, app: &mut App) {
    let chunks = Layout::default()
        .direction(Direction::Horizontal)
        .constraints([Constraint::Percentage(30), Constraint::Percentage(70)].as_ref())
        .split(f.size());

    draw_sidebar(f, app, chunks[0]);
    draw_main_content(f, app, chunks[1]);

    if app.show_hint {
        draw_hint_popup(f, app);
    }
}

fn draw_sidebar(f: &mut Frame, app: &App, area: Rect) {
    let mut styled_items = Vec::new();
    for (t_idx, topic) in app.topics.iter().enumerate() {
        let is_topic_selected = app.selection_mode == SelectionMode::Topic && t_idx == app.current_topic_index;

        let mut topic_style = Style::default().add_modifier(Modifier::BOLD).fg(Color::Blue);
        if is_topic_selected {
            topic_style = topic_style.add_modifier(Modifier::REVERSED);
        }

        let indicator = if topic.open { "▼" } else { "▶" };
        styled_items.push(ListItem::new(Span::styled(
            format!("{} {} {}", indicator, "📂", topic.name),
            topic_style,
        )));

        if topic.open {
            for (e_idx, exercise) in topic.exercises.iter().enumerate() {
                let is_completed = app.progress.is_completed(&exercise.name);
                let is_selected = app.selection_mode == SelectionMode::Exercise
                    && t_idx == app.current_topic_index
                    && e_idx == app.current_exercise_index;

                let status_icon = if is_completed { "✓" } else { " " };
                let mut style = if is_completed {
                    Style::default().fg(Color::Green)
                } else {
                    Style::default().fg(Color::White)
                };

                if is_selected {
                    style = style.add_modifier(Modifier::REVERSED);
                }

                let content = format!("    {} {}", status_icon, exercise.name);
                styled_items.push(ListItem::new(Span::styled(content, style)));
            }
        }
    }

    let list = List::new(styled_items)
        .block(Block::default().borders(Borders::ALL).title("Exercises"));

    f.render_widget(list, area);
}

fn draw_main_content(f: &mut Frame, app: &App, area: Rect) {
    let chunks = Layout::default()
        .direction(Direction::Vertical)
        .constraints([Constraint::Percentage(20), Constraint::Percentage(80)].as_ref())
        .split(area);

    // Info Block or Topic Summary
    match app.selection_mode {
        SelectionMode::Topic => {
            if let Some(topic) = app.topics.get(app.current_topic_index) {
                let completed_count = topic.exercises.iter()
                    .filter(|e| app.progress.is_completed(&e.name))
                    .count();
                let total_count = topic.exercises.len();

                let summary = vec![
                    Line::from(Span::styled(format!("Topic: {}", topic.name), Style::default().add_modifier(Modifier::BOLD).fg(Color::Blue))),
                    Line::from(""),
                    Line::from(format!("Progress: {} / {} completed", completed_count, total_count)),
                    Line::from(""),
                    Line::from(Span::styled("Instructions:", Style::default().fg(Color::Yellow))),
                    Line::from("  • Press 'Enter' to expand/collapse topic"),
                    Line::from("  • Press 'j' to move down"),
                ];

                let p = Paragraph::new(summary)
                    .block(Block::default().borders(Borders::ALL).title("Topic Summary"))
                    .wrap(Wrap { trim: true });
                f.render_widget(p, chunks[0]);
            }
        }
        SelectionMode::Exercise => {
            if let Some(exercise) = app.current_exercise() {
                let path_text = format!("Path: {}", exercise.path.display());
                let mode_text = format!("Mode: {:?}", exercise.mode);
                // Hint is hidden by default now
                let hint_msg = "Press 'h' for hint";

                let info_paragraph = Paragraph::new(vec![
                    Line::from(Span::styled(path_text, Style::default().add_modifier(Modifier::BOLD))),
                    Line::from(mode_text),
                    Line::from(""),
                    Line::from(Span::styled("Instructions:", Style::default().fg(Color::Yellow))),
                    Line::from("  • Press 'Enter' or 'e' to open in Editor"),
                    Line::from("  • Edit the file and save to verify"),
                    Line::from("  • 'q' to Quit"),
                    Line::from(""),
                    Line::from(Span::styled(hint_msg, Style::default().fg(Color::Cyan))),
                ])
                .block(Block::default().borders(Borders::ALL).title("Details"))
                .wrap(Wrap { trim: true });

                f.render_widget(info_paragraph, chunks[0]);
            }
        }
    }

    // Output Block
    let output_block = Block::default().borders(Borders::ALL).title("Output");
    if let Some(output) = &app.output {
        let mut lines = Vec::new();
        if output.success {
            lines.push(Line::from(Span::styled("✓ Verification Successful!", Style::default().fg(Color::Green).add_modifier(Modifier::BOLD))));
        } else {
            lines.push(Line::from(Span::styled("✗ Verification Failed", Style::default().fg(Color::Red).add_modifier(Modifier::BOLD))));
        }

        lines.push(Line::from(""));

        if !output.stdout.is_empty() {
            lines.push(Line::from(Span::styled("STDOUT:", Style::default().fg(Color::Blue))));
            for line in output.stdout.lines() {
                lines.push(Line::from(line));
            }
        }

        if !output.stderr.is_empty() {
             lines.push(Line::from(""));
             lines.push(Line::from(Span::styled("STDERR:", Style::default().fg(Color::Red))));
             for line in output.stderr.lines() {
                lines.push(Line::from(line));
            }
        }

        let output_paragraph = Paragraph::new(lines)
            .block(output_block)
            .wrap(Wrap { trim: false }); // Don't wrap code output too aggressively

        f.render_widget(output_paragraph, chunks[1]);
    } else {
        let placeholder = Paragraph::new("Waiting for verification...")
            .block(output_block)
            .style(Style::default().fg(Color::DarkGray));
        f.render_widget(placeholder, chunks[1]);
    }
}

fn draw_hint_popup(f: &mut Frame, app: &App) {
    if let Some(exercise) = app.current_exercise() {
        let block = Block::default().title("Hint").borders(Borders::ALL);
        let text = vec![
            Line::from(Span::styled(&exercise.hint, Style::default().fg(Color::Cyan))),
            Line::from(""),
            Line::from(Span::styled("Press Esc or h to close", Style::default().fg(Color::DarkGray))),
        ];
        let paragraph = Paragraph::new(text)
            .block(block)
            .wrap(Wrap { trim: true })
            .alignment(Alignment::Center);

        let area = centered_rect(60, 20, f.size());
        f.render_widget(Clear, area); // Clear out the background
        f.render_widget(paragraph, area);
    }
}

/// helper function to create a centered rect using up certain percentage of the available rect `r`
fn centered_rect(percent_x: u16, percent_y: u16, r: Rect) -> Rect {
    let popup_layout = Layout::default()
        .direction(Direction::Vertical)
        .constraints(
            [
                Constraint::Percentage((100 - percent_y) / 2),
                Constraint::Percentage(percent_y),
                Constraint::Percentage((100 - percent_y) / 2),
            ]
            .as_ref(),
        )
        .split(r);

    let popup_layout = Layout::default()
        .direction(Direction::Horizontal)
        .constraints(
            [
                Constraint::Percentage((100 - percent_x) / 2),
                Constraint::Percentage(percent_x),
                Constraint::Percentage((100 - percent_x) / 2),
            ]
            .as_ref(),
        )
        .split(popup_layout[1]);

    popup_layout[1]
}
