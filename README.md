## About the project
Zest Assistant main purpose was to help Zest players access their notes in more organize way. The tool works as a terminal command.

### Built with
Pure C with CMake was used without any additional extensions.

## Getting Started
Download the package with .exe file. Afterwards move .exe file wherever you want and add its path to $PATH variable, so you can run the program from any place.

### Prerequisites
Works only on Windows.

## Usage
Launch the program in terminal with the command `Zest.exe` or `Zest.exe -h` to list all possible commands.
Below I provide the former mentioned command output.
```
You are using Zest Assistant
without providing level_number program will take the furthest one
-E [level_number] - open current level notes to edit
-I [level_number] - open current level image to edit
-IE [level_number] - open current level notes and image to edit
-A path_to_image level_number - moves image to current level directory
-O [level_number] - open level in browser
-L - show all levels with appropriate links
```

## License
Distributed under the MIT License. See LICENSE.txt for more information.
