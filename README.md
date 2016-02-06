# todo-cmd
A command line utility that provides a simple todo task manager for the Linux/Macosx command line.
Old enough, recently found in a nasty backup (10+ years old - 2016)

## Installation

![alt usage](https://raw.githubusercontent.com/petmakris/todo-cmd/master/installtion.png)

## Usage

![alt usage](https://raw.githubusercontent.com/petmakris/todo-cmd/master/usage.png)

# Notes

```
make && make install
```

## Uninstall

```
make uninstall
```

Append the following in your `bash_profile` (or `.bashrc`) file:

```bash
C1="\[\033[29;13;1m\]"
EC="\[\033[0m\]"
C2="\[\033[49;31;1m\]"
PS1="[$C1\`todo-getsize\`$EC] $C2\W $EC> "
```

To reset todos remove the todo-storage file

```
rm ~/.consoletodo.db
```

