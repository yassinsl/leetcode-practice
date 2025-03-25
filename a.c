# ~/.bashrc: executed by bash(1) for non-login shells.

# Color Definitions
RESET='\[\033[0m\]'       # Reset to default color
BLACK='\[\033[0;30m\]'
RED='\[\033[0;31m\]'
GREEN='\[\033[0;32m\]'    # User and hostname color
YELLOW='\[\033[0;33m\]'
BLUE='\[\033[0;34m\]'     # Directory color
MAGENTA='\[\033[0;35m\]'
CYAN='\[\033[0;36m\]'     # Symbolic links color
WHITE='\[\033[0;37m\]'

# Prompt Configuration
# Format: username@hostname:directory$
PS1="${GREEN}\u@\h${RESET}:${BLUE}\w${RESET}$ "

# Customize the terminal title
PROMPT_COMMAND='echo -ne "\033]0;${USER}@${HOSTNAME}: ${PWD}\007"'

# History Configuration
HISTSIZE=10000            # Number of commands to remember in history
HISTFILESIZE=20000        # Maximum number of lines in history file
HISTCONTROL=ignoredups:erasedups  # Ignore duplicate commands
shopt -s histappend       # Append to history, don't overwrite

# Shell Options
shopt -s checkwinsize    # Update window size after each command
shopt -s globstar        # Enable ** for recursive globbing
shopt -s progcomp        # Enable programmable completion features

# Color Configuration for LS
export LS_COLORS='
di=34:fi=0:ln=36:pi=33:so=35:bd=1;33:cd=1;33:or=31:ex=32:
*.tar=31:*.tgz=31:*.zip=31:*.gz=31:*.bz2=31:*.7z=31:*.rar=31:
*.jpg=35:*.jpeg=35:*.png=35:*.gif=35:*.bmp=35:
*.pdf=31:*.doc=31:*.docx=31:*.xls=31:*.xlsx=31:
*.c=32:*.cpp=32:*.py=32:*.rb=32:*.js=32:*.ts=32:
*.html=36:*.css=36:*.json=36:*.xml=36
'

# Color Support
alias ls='ls --color=auto'
alias grep='grep --color=auto'
alias fgrep='fgrep --color=auto'
alias egrep='egrep --color=auto'

# Apply color settings
eval "$(dircolors -b)"

# Common Aliases
alias ll='ls -la --color=auto'
alias lh='ls -lah --color=auto'
alias mkdir='mkdir -p'
alias ..='cd ..'
alias ...='cd ../..'

# Git Aliases
alias gs='git status'
alias gco='git checkout'
alias gd='git diff'
alias ga='git add'
alias gc='git commit'
alias gp='git push'
alias gl='git pull'

# Development Aliases
alias ft="/home/ylahssin/francinette/tester.sh"
alias unreal="~/goinfre/Linux_Unreal_Engine_5.5.3/Engine/Binaries/Linux/UnrealEditor"
alias vbox='virtualbox'
alias bg='xrandr -s 2560x1440'
alias xclean="/bin/bash $HOME/xclean.sh"

# Custom Functions
# Create and enter directory
mkcd() {
    mkdir -p "$1" && cd "$1"
}

# Extract various archive formats
extract() {
    if [ -f "$1" ]; then
        case "$1" in
            *.tar.bz2)   tar xjf "$1"     ;;
            *.tar.gz)    tar xzf "$1"     ;;
            *.bz2)       bunzip2 "$1"     ;;
            *.rar)       unrar x "$1"     ;;
            *.gz)        gunzip "$1"      ;;
            *.tar)       tar xf "$1"      ;;
            *.tbz2)      tar xjf "$1"     ;;
            *.tgz)       tar xzf "$1"     ;;
            *.zip)       unzip "$1"       ;;
            *.Z)         uncompress "$1"  ;;
            *)           echo "'$1' cannot be extracted via extract()" ;;
        esac
    else
        echo "'$1' is not a valid file"
    fi
}

# Environment Variables
export EDITOR=vim
export PAGER=less
export USER42="ylahssin"
export MAIL42="ylahssin@student.42.fr"

# PATH Configurations
export PATH="$HOME/bin:$PATH"
export PATH="$HOME/.local/bin:$PATH"
export PATH="$HOME/.local/nvim/bin:$PATH"
export PATH="$HOME/nvim/bin:$PATH"
export PATH="$HOME/nvim-linux64/bin:$PATH"
export PATH="$HOME/nvim-10:$PATH"
export LD_LIBRARY_PATH=~/.local/lib:$LD_LIBRARY_PATH

# Additional PATH from pipx
export PATH="$PATH:/home/ylahssin/.local/bin:/home/ylahssin/"

# Source Global Definitions
if [ -f /etc/bashrc ]; then
    . /etc/bashrc
fi

# Auto-completion
if [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
fi

# Optional: Add custom completion scripts
# if [ -d ~/.bash_completion.d ]; then
#     for file in ~/.bash_completion.d/*; do
#         source "$file"
#     done
# fi
