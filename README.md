# todo-cmd
A command line utility that provides a simple todo task manager for the Linux/Macosx command line

## Install

```
make && make install
```

## Uninstall

```
make uninstall
```

Append the following in your `bash_profile` (or `.bashrc`) files:

```bash
C1="\[\033[29;13;1m\]"
EC="\[\033[0m\]"
C2="\[\033[49;31;1m\]"
PS1="[$C1\`todo-getsize\`$EC] $C2\W $EC> "
```
