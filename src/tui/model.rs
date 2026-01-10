use crate::exercise::Exercise;
use crate::progress::Progress;
use crate::verify::VerificationOutput;
use std::collections::HashMap;

#[derive(Debug, Clone)]
pub struct Topic {
    pub name: String,
    pub exercises: Vec<Exercise>,
    pub open: bool,
}

#[derive(Debug, Clone, PartialEq)]
pub enum SelectionMode {
    Topic,
    Exercise,
}

pub struct App {
    pub topics: Vec<Topic>,
    pub current_topic_index: usize,
    pub current_exercise_index: usize,
    pub selection_mode: SelectionMode,
    pub show_hint: bool,
    pub progress: Progress,
    pub output: Option<VerificationOutput>,
    pub should_quit: bool,
    pub processing: bool,
}

impl App {
    pub fn new(exercises: Vec<Exercise>) -> Self {
        let progress = Progress::load();

        // Group exercises by topic (directory name)
        let mut topic_map: HashMap<String, Vec<Exercise>> = HashMap::new();
        for exercise in exercises {
            let topic_name = exercise.path.parent()
                .and_then(|p| p.file_name())
                .and_then(|n| n.to_str())
                .unwrap_or("unknown")
                .to_string();

            topic_map.entry(topic_name).or_default().push(exercise);
        }

        // Sort topics to ensure order (e.g. 1_intro, 2_variables)
        let mut topics: Vec<Topic> = topic_map.into_iter()
            .map(|(name, exercises)| Topic { name, exercises, open: false })
            .collect();
        topics.sort_by(|a, b| human_sort(&a.name, &b.name));

        // Sort exercises within topics
        for topic in &mut topics {
             topic.exercises.sort_by(|a, b| human_sort(&a.name, &b.name));
        }

        // Find first unfinished exercise
        let mut start_topic = 0;
        let mut start_ex = 0;
        'outer: for (t_idx, topic) in topics.iter().enumerate() {
            for (e_idx, ex) in topic.exercises.iter().enumerate() {
                if !progress.is_completed(&ex.name) {
                    start_topic = t_idx;
                    start_ex = e_idx;
                    break 'outer;
                }
            }
        }

        if let Some(topic) = topics.get_mut(start_topic) {
            topic.open = true;
        }

        App {
            topics,
            current_topic_index: start_topic,
            current_exercise_index: start_ex,
            selection_mode: SelectionMode::Exercise,
            show_hint: false,
            progress,
            output: None,
            should_quit: false,
            processing: false,
        }
    }

    pub fn current_exercise(&self) -> Option<&Exercise> {
        if self.selection_mode == SelectionMode::Topic {
            return None;
        }
        self.topics.get(self.current_topic_index)
            .and_then(|t| t.exercises.get(self.current_exercise_index))
    }

    pub fn next(&mut self) {
        match self.selection_mode {
            SelectionMode::Topic => {
                let topic = &self.topics[self.current_topic_index];
                if topic.open && !topic.exercises.is_empty() {
                    self.selection_mode = SelectionMode::Exercise;
                    self.current_exercise_index = 0;
                } else {
                    if self.current_topic_index + 1 < self.topics.len() {
                        self.current_topic_index += 1;
                    }
                }
            }
            SelectionMode::Exercise => {
                let topic = &self.topics[self.current_topic_index];
                if self.current_exercise_index + 1 < topic.exercises.len() {
                    self.current_exercise_index += 1;
                } else {
                    if self.current_topic_index + 1 < self.topics.len() {
                        self.current_topic_index += 1;
                        self.selection_mode = SelectionMode::Topic;
                        // Reset exercise index for when we expand next topic
                        self.current_exercise_index = 0;
                    }
                }
            }
        }
    }

    pub fn previous(&mut self) {
        match self.selection_mode {
            SelectionMode::Topic => {
                if self.current_topic_index > 0 {
                    self.current_topic_index -= 1;
                    let prev_topic = &self.topics[self.current_topic_index];
                    if prev_topic.open && !prev_topic.exercises.is_empty() {
                        self.selection_mode = SelectionMode::Exercise;
                        self.current_exercise_index = prev_topic.exercises.len() - 1;
                    } else {
                        self.selection_mode = SelectionMode::Topic;
                    }
                }
            }
            SelectionMode::Exercise => {
                if self.current_exercise_index > 0 {
                    self.current_exercise_index -= 1;
                } else {
                    self.selection_mode = SelectionMode::Topic;
                }
            }
        }
    }

    pub fn toggle_topic(&mut self) {
        if let Some(topic) = self.topics.get_mut(self.current_topic_index) {
            topic.open = !topic.open;
            // If we closed the topic, make sure we are in topic selection mode
            // (Though toggle is only called from Topic mode usually)
            if !topic.open && self.selection_mode == SelectionMode::Exercise {
                self.selection_mode = SelectionMode::Topic;
            }
        }
    }
}

// Simple numeric aware sort (e.g. 2 < 10)
fn human_sort(a: &str, b: &str) -> std::cmp::Ordering {
    // Extract leading numbers if possible
    let num_a = a.chars().take_while(|c| c.is_numeric()).collect::<String>();
    let num_b = b.chars().take_while(|c| c.is_numeric()).collect::<String>();

    match (num_a.parse::<u32>(), num_b.parse::<u32>()) {
        (Ok(na), Ok(nb)) => {
            if na != nb {
                return na.cmp(&nb);
            }
        }
        _ => {}
    }
    a.cmp(b)
}
