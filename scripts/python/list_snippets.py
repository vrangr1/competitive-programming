import os
import argparse
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

PREFIX_LENGTH = 23

def format(line : str, setting : str ):
    return f'{setting}{line}{CLEAR}'

def parse_args(args=None):
    parser = argparse.ArgumentParser(description ='VS Code Snippet Generator')
    parser.add_argument('snippets_dir', type=str, nargs='?',\
                        default="/Users/anavp/home/programming/competitive-programming/algo/snippets_code",\
                        help='path to the directory where all the cpp snippets are stored')
    args = parser.parse_args()
    return args

def get_files(dir_path : str) -> 'list[str]':
    files = os.listdir(dir_path)
    cpp_files = list()
    for file in files:
        file_path = os.path.join(dir_path,file)
        if not os.path.isfile(file_path) or os.path.splitext(os.path.basename(file_path))[1] != ".cpp":
            continue
        cpp_files.append(file_path)
    return cpp_files

def process_snippet(file_path : str) -> None:
    file = open(file_path,'r')
    lines = file.readlines()
    ind = next((ind for ind,line in enumerate(lines) if line.startswith("#ifndef")),None)
    assert ind >= 3, "The details for VS Code snippets (title, prefix, description) seems to be missing in the beginning of the cpp file."
    lines = lines[:ind]
    details_list = tuple(["prefix", "description"])
    prefix = description = None
    for line in lines:
        line = line.strip()
        if not line.startswith(details_list): continue
        detail = line.split(' ',1)[0]
        if detail == "prefix": prefix = line.split(':',1)[1].strip()
        else: description = line.split(':',1)[1].strip()
    assert prefix is not None, "prefix cannot be None"
    assert description is not None, "description cannot be None"
    line = prefix
    line = line.ljust(PREFIX_LENGTH)
    print(format(line,RED_BOLD),end="")
    print(description)

if __name__ == '__main__':
    args = parse_args()
    assert args.snippets_dir != "", "path to the source directory of snippets cannot be empty!"
    
    files = get_files(args.snippets_dir)
    print(format("List of snippets are as follows:",BOLD))
    print(format("PREFIX",RED_BOLD+UNDERLINE) + " " * (PREFIX_LENGTH-6) + format("Description",BOLD+UNDERLINE))
    for file in files:
        process_snippet(file)