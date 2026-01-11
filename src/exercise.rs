use serde::Deserialize;
use std::fmt::{self, Display, Formatter};
use std::path::PathBuf;

#[derive(Deserialize, Debug, Clone, PartialEq)]
#[serde(rename_all = "lowercase")]
pub enum Mode {
    Compile,
    Test,
    Run,
}

#[derive(Deserialize, Debug, Clone)]
pub struct Exercise {
    pub name: String,
    pub path: PathBuf,
    pub mode: Mode,
    pub hint: String,
    pub output: Option<String>,
    pub stdin: Option<String>,
    pub args: Option<Vec<String>>,
}

#[derive(Deserialize, Debug)]
pub struct Info {
    pub exercises: Vec<Exercise>,
}

impl Display for Exercise {
    fn fmt(&self, f: &mut Formatter) -> fmt::Result {
        write!(f, "{}", self.path.display())
    }
}
