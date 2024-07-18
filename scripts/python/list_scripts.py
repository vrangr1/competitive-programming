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
    parser = argparse.ArgumentParser(description ='Internal program to list all the scripts. Made to be used by the shell script "list_scripts"')
    parser.add_argument('scripts_dir', type=str, nargs='?',\
                        default="/Users/anavp/home/programming/competitive-programming/scripts/bash",\
                        help='path to the directory where all the shell scripts are stored')
    parser.add_argument("-a", "--all", action="store_true",\
                        help="Use to print even the hidden scripts")
    args = parser.parse_args()
    return args

def get_files(dir_path : str) -> 'list[str]':
    files = os.listdir(dir_path)
    shell_files = list()
    for file in files:
        file_path = os.path.join(dir_path,file)
        if not os.path.isfile(file_path):
            continue
        shell_files.append(file_path)
    return shell_files

def process_script(file_path : str, print_hidden = False) -> None:
    file = open(file_path,'r')
    lines = file.readlines()
    ind = next((ind for ind,line in enumerate(lines) if line.startswith("COMMENT")),None)
    assert ind is not None and ind >= 5, "The details for shell scripts (command, description, list) seems to be missing in the beginning of the shell script."
    lines = lines[:ind]
    details_list = tuple(["command", "description", "list"])
    command = description = list_script = None
    for line in lines:
        line = line.strip()
        if not line.startswith(details_list): continue
        detail = line.split(' ',1)[0]
        if detail == "command": command = line.split(':',1)[1].strip()
        elif detail == "description": description = line.split(':',1)[1].strip()
        else : list_script = line.split(':',1)[1].strip()
    assert command is not None, "prefix cannot be None"
    assert description is not None, "description cannot be None"
    assert list_script == "true" or list_script == "false"
    list_script = bool(list_script == "true")
    color = RED_BOLD
    if not list_script:
        if not print_hidden: return
        color = MAGENTA_BOLD
    line = command
    line = line.ljust(PREFIX_LENGTH)
    print(format(line,color),end="")
    print(description)

if __name__ == '__main__':
    args = parse_args()
    assert args.scripts_dir != "", "path to the source directory of scripts cannot be empty!"
    files = get_files(args.scripts_dir)
    print(format("List of scripts are as follows:",BOLD))
    print(format("COMMAND",RED_BOLD+UNDERLINE) + " " * (PREFIX_LENGTH-6) + format("Description",BOLD+UNDERLINE))
    for file in files:
        process_script(file, args.all)