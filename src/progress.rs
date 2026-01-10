use serde::{Deserialize, Serialize};
use std::collections::HashSet;
use std::fs;
use std::path::Path;

#[derive(Serialize, Deserialize, Default, Debug, Clone)]
pub struct Progress {
    pub completed_exercises: HashSet<String>,
}

impl Progress {
    pub fn load() -> Self {
        let path = Path::new(".clings_state.toml");
        if !path.exists() {
            return Progress::default();
        }

        let content = fs::read_to_string(path).unwrap_or_default();
        toml::from_str(&content).unwrap_or_default()
    }

    pub fn save(&self) {
        let path = Path::new(".clings_state.toml");
        let content = toml::to_string(self).expect("Failed to serialize progress");
        fs::write(path, content).expect("Failed to write progress file");
    }

    pub fn mark_completed(&mut self, exercise_name: String) {
        self.completed_exercises.insert(exercise_name);
        self.save();
    }

    pub fn is_completed(&self, exercise_name: &str) -> bool {
        self.completed_exercises.contains(exercise_name)
    }
}
