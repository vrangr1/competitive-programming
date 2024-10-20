: <<COMMENT
Details for script lister program:
command     : constants_cp.sh
description : helper file for all constants
list        : false
COMMENT
# Shell script to store all the constants

# Various Constants and helper functions
COMPILER="g++-14"

## File paths
CP_ROOT="/Users/anavp/home/programming/competitive-programming/"
ALGO_DIRECTORY="/opt/homebrew/Cellar/gcc/14.1.0/include/c++/14/algo"
SNIPPET_GENERATOR="/Users/anavp/home/programming/snippet_generator/src/snippet_generator.py"
CPR=$CP_ROOT"scripts/bash/cpr"
TEMPLATE=$CP_ROOT"algo/template.cpp"
DEBUG_HEADER=$CP_ROOT"algo/debug.hpp"
BASH_SCRIPT_DIRECTORY=$CP_ROOT"scripts/bash/"
LIST_SNIPPETS_PYTHON_SCRIPT=$CP_ROOT"scripts/python/list_snippets.py"
LIST_SCRIPTS_PYTHON_SCRIPT=$CP_ROOT"scripts/python/list_scripts.py"
TEST_CASE_GENERATOR=$CP_ROOT"algo/test/generator.cpp"
BRUTE_FORCE=$TEMPLATE
CHECKER=$CP_ROOT"algo/test/checker.cpp"

## Constants:
OUTPUT_START="OUTPUT_BEGINS"
OUTPUT_END="OUTPUT_ENDS"

### Text formatting ###

CLEAR="\033[0m"

# Text settings.
BOLD="\033[1m"
UNDERLINE="\033[4m"

# Text color.
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"

# Text color with bold font.
RED_BOLD="\033[1;31m"
GREEN_BOLD="\033[1;32m"
YELLOW_BOLD="\033[1;33m"
BLUE_BOLD="\033[1;34m"
MAGENTA_BOLD="\033[1;35m"
CYAN_BOLD="\033[1;36m"

# Background color.
RED_BG="\033[41m"
GREEN_BG="\033[42m"
YELLOW_BG="\033[43m"
BLUE_BG="\033[44m"
MAGENTA_BG="\033[45m"
CYAN_BG="\033[46m"

# Background color with bold font.
RED_BG_BOLD="\033[1;41m"
GREEN_BG_BOLD="\033[1;42m"
YELLOW_BG_BOLD="\033[1;43m"
BLUE_BG_BOLD="\033[1;44m"
MAGENTA_BG_BOLD="\033[1;45m"
CYAN_BG_BOLD="\033[1;46m"

### End of text formatting ###