use ratatui::{
    layout::{Alignment, Constraint, Direction, Layout, Rect},
    style::{Modifier, Style},
    text::{Line, Span},
    widgets::{Block, BorderType, Borders, Clear, List, ListItem, Paragraph, Wrap},
    Frame,
};
use crate::tui::model::{App, SelectionMode};
use crate::tui::theme::*;

pub fn ui(f: &mut Frame, app: &mut App) {
    let chunks = Layout::default()
        .direction(Direction::Horizontal)
        .constraints([Constraint::Percentage(45), Constraint::Percentage(55)].as_ref())
        .split(f.size());

    draw_sidebar(f, app, chunks[0]);
    draw_main_content(f, app, chunks[1]);

    if app.show_hint {
        draw_hint_popup(f, app);
    }

    if app.show_quit_popup {
        draw_quit_popup(f);
    }
}

fn draw_sidebar(f: &mut Frame, app: &App, area: Rect) {
    let chunks = Layout::default()
        .direction(Direction::Vertical)
        .constraints([
            Constraint::Length(8), // Fixed height for logo
            Constraint::Min(0),    // Remaining space for list
        ].as_ref())
        .split(area);

    draw_logo(f, chunks[0]);
    draw_exercise_list(f, app, chunks[1]);
}

fn draw_logo(f: &mut Frame, area: Rect) {
    let logo_text = vec![
        "  ___ _ _               ",
        " / __| (_)_ _  __ _ ___ ",
        "| (__| | | ' \\/ _` (_-< ",
        " \\___|_|_|_||_\\__, /__/ ",
        "              |___/     ",
    ];

    // Actually, let's make it look nice with a rounded border box
    let block = Block::default()
        .borders(Borders::ALL)
        .border_type(BorderType::Rounded)
        .border_style(Style::default().fg(GRUVBOX_BLUE))
        .title("CLings")
        .title_alignment(Alignment::Center);

    let logo_widget = Paragraph::new(logo_text.join("\n"))
        .block(block)
        .style(Style::default().fg(GRUVBOX_ORANGE).add_modifier(Modifier::BOLD))
        .alignment(Alignment::Center);

    f.render_widget(logo_widget, area);
}

fn draw_exercise_list(f: &mut Frame, app: &App, area: Rect) {
    let mut styled_items = Vec::new();
    for (t_idx, topic) in app.topics.iter().enumerate() {
        let is_topic_selected = app.selection_mode == SelectionMode::Topic && t_idx == app.current_topic_index;

        let mut topic_style = Style::default().add_modifier(Modifier::BOLD).fg(GRUVBOX_BLUE);
        if is_topic_selected {
            topic_style = topic_style.bg(GRUVBOX_SELECTION_BG).fg(GRUVBOX_FG);
        }

        let indicator = if topic.open { "▼" } else { "▶" };

        let all_completed = !topic.exercises.is_empty()
            && topic.exercises
                .iter()
                .all(|e| app.progress.is_completed(&e.name));

        let mut spans = vec![Span::styled(format!("{} ", indicator), topic_style)];

        if all_completed {
            let mut checkmark_style = Style::default().fg(GRUVBOX_GREEN);
            if is_topic_selected {
                checkmark_style = checkmark_style.bg(GRUVBOX_SELECTION_BG);
            }
            spans.push(Span::styled("✓ ", checkmark_style));
        }

        spans.push(Span::styled(format!("{}/", topic.name), topic_style));

        styled_items.push(ListItem::new(Line::from(spans)));

        if topic.open {
            for (e_idx, exercise) in topic.exercises.iter().enumerate() {
                let is_completed = app.progress.is_completed(&exercise.name);
                let is_selected = app.selection_mode == SelectionMode::Exercise
                    && t_idx == app.current_topic_index
                    && e_idx == app.current_exercise_index;

                let status_icon = if is_completed { "✓" } else { " " };
                let mut style = if is_completed {
                    Style::default().fg(GRUVBOX_GREEN)
                } else {
                    Style::default().fg(GRUVBOX_FG)
                };

                if is_selected {
                    style = style.bg(GRUVBOX_SELECTION_BG).add_modifier(Modifier::BOLD);
                }

                let content = format!("    {} {}", status_icon, exercise.name);
                styled_items.push(ListItem::new(Span::styled(content, style)));
            }
        }
    }

    let list = List::new(styled_items)
        .block(
            Block::default()
                .borders(Borders::ALL)
                .border_type(BorderType::Rounded)
                .border_style(Style::default().fg(GRUVBOX_FG))
                .title("Exercises")
        );

    f.render_widget(list, area);
}

fn draw_main_content(f: &mut Frame, app: &App, area: Rect) {
    let chunks = Layout::default()
        .direction(Direction::Vertical)
        .constraints([Constraint::Percentage(30), Constraint::Percentage(70)].as_ref())
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
                    Line::from(Span::styled(format!("Topic: {}", topic.name), Style::default().add_modifier(Modifier::BOLD).fg(GRUVBOX_BLUE))),
                    Line::from(""),
                    Line::from(format!("Progress: {} / {} completed", completed_count, total_count)),
                    Line::from(""),
                    Line::from(Span::styled("Instructions:", Style::default().fg(GRUVBOX_YELLOW))),
                    Line::from("  • Press 'Enter' or 'l' to expand/collapse topic"),
                    Line::from("  • Press 'j' / 'Down' to move down"),
                    Line::from("  • Press 'k' / 'Up' to move up"),
                    Line::from("  • Press 'q' to Quit"),
                ];

                let p = Paragraph::new(summary)
                    .block(
                        Block::default()
                            .borders(Borders::ALL)
                            .border_type(BorderType::Rounded)
                            .border_style(Style::default().fg(GRUVBOX_FG))
                            .title("Topic Summary")
                    )
                    .wrap(Wrap { trim: true });
                f.render_widget(p, chunks[0]);
            }
        }
        SelectionMode::Exercise => {
            if let Some(exercise) = app.current_exercise() {
                let path_text = format!("Path: {}", exercise.path.display());
                let mode_text = format!("Mode: {:?}", exercise.mode);
                let hint_msg = "Press 'h' for hint";

                let info_paragraph = Paragraph::new(vec![
                    Line::from(Span::styled(path_text, Style::default().add_modifier(Modifier::BOLD).fg(GRUVBOX_FG))),
                    Line::from(Span::styled(mode_text, Style::default().fg(GRUVBOX_FG))),
                    Line::from(""),
                    Line::from(Span::styled("Instructions:", Style::default().fg(GRUVBOX_YELLOW))),
                    Line::from("  • Press 'Enter' or 'e' to open in Editor"),
                    Line::from("  • Edit the file and save to verify"),
                    Line::from("  • Press 'j' / 'Down' for next item"),
                    Line::from("  • Press 'k' / 'Up' for prev item"),
                    Line::from("  • Press 'q' to Quit"),
                    Line::from(""),
                    Line::from(Span::styled(hint_msg, Style::default().fg(GRUVBOX_CYAN))),
                ])
                .block(
                    Block::default()
                        .borders(Borders::ALL)
                        .border_type(BorderType::Rounded)
                        .border_style(Style::default().fg(GRUVBOX_FG))
                        .title("Details")
                )
                .wrap(Wrap { trim: true });

                f.render_widget(info_paragraph, chunks[0]);
            }
        }
    }

    // Output Block
    let output_block = Block::default()
        .borders(Borders::ALL)
        .border_type(BorderType::Rounded)
        .border_style(Style::default().fg(GRUVBOX_FG))
        .title("Output");

    if let Some(output) = &app.output {
        let mut lines = Vec::new();
        if output.success {
            lines.push(Line::from(Span::styled("✓ Verification Successful!", Style::default().fg(GRUVBOX_GREEN).add_modifier(Modifier::BOLD))));
        } else {
            lines.push(Line::from(Span::styled("✗ Verification Failed", Style::default().fg(GRUVBOX_RED).add_modifier(Modifier::BOLD))));
        }

        lines.push(Line::from(""));

        if !output.stdout.is_empty() {
            lines.push(Line::from(Span::styled("STDOUT:", Style::default().fg(GRUVBOX_BLUE))));
            for line in output.stdout.lines() {
                lines.push(Line::from(Span::styled(line, Style::default().fg(GRUVBOX_FG))));
            }
        }

        if !output.stderr.is_empty() {
             lines.push(Line::from(""));
             lines.push(Line::from(Span::styled("STDERR:", Style::default().fg(GRUVBOX_RED))));
             for line in output.stderr.lines() {
                lines.push(Line::from(Span::styled(line, Style::default().fg(GRUVBOX_FG))));
            }
        }

        let output_paragraph = Paragraph::new(lines)
            .block(output_block)
            .wrap(Wrap { trim: false });

        f.render_widget(output_paragraph, chunks[1]);
    } else {
        let placeholder = Paragraph::new("Waiting for verification...")
            .block(output_block)
            .style(Style::default().fg(GRUVBOX_FG)); // Changed to FG for visibility
        f.render_widget(placeholder, chunks[1]);
    }
}

fn draw_hint_popup(f: &mut Frame, app: &App) {
    if let Some(exercise) = app.current_exercise() {
        let block = Block::default()
            .title("Hint")
            .borders(Borders::ALL)
            .border_type(BorderType::Rounded)
            .border_style(Style::default().fg(GRUVBOX_CYAN));

        let text = vec![
            Line::from(Span::styled(&exercise.hint, Style::default().fg(GRUVBOX_FG))),
            Line::from(""),
            Line::from(Span::styled("Press Esc or h to close", Style::default().fg(GRUVBOX_SELECTION_BG))), // Darker text for secondary info
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

fn draw_quit_popup(f: &mut Frame) {
    let block = Block::default()
        .title("Quit")
        .borders(Borders::ALL)
        .border_type(BorderType::Rounded)
        .border_style(Style::default().fg(GRUVBOX_RED));

    let text = vec![
        Line::from(Span::styled("Are you sure you want to quit?", Style::default().fg(GRUVBOX_RED).add_modifier(Modifier::BOLD))),
        Line::from(""),
        Line::from(Span::styled("(y) Yes / (n) No", Style::default().fg(GRUVBOX_FG))),
    ];
    let paragraph = Paragraph::new(text)
        .block(block)
        .wrap(Wrap { trim: true })
        .alignment(Alignment::Center);

    let area = centered_rect(40, 15, f.size());
    f.render_widget(Clear, area); // Clear out the background
    f.render_widget(paragraph, area);
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
