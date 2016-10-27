@echo off
::
:: Install Lua for Windows (http://luaforwindows.luaforge.net) to use.
::

cd text

lua markdown.lua index.md
lua markdown.lua faq.md
lua markdown.lua building.md
lua markdown.lua wxwidgets_install.md
lua markdown.lua gcc_install.md
lua markdown.lua svn_install.md

copy *.html ..\

cd ..

echo Finshied generating documentation...
pause
