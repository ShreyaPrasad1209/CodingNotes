# GSoC Project Report 2
**Project Name:** GDScript Language Server<br>
**Student:** Ankit Priyarup ([@ankitpriyarup](https://github.com/ankitpriyarup))<br>
**Mentors:** Geequlim ([@geequlim](https://github.com/geequlim)) and Jiacheng Lu ([@jason0214](https://github.com/jason0214))<br>
**Repositories:** <br>
- Student Server Working Branch: https://github.com/ankitpriyarup/godot/tree/lsp<br>
- Mentor Server Working Branch: https://github.com/GodotExplorer/godot/tree/gdscript-lsp<br>
- Student Client Working Branch: https://github.com/ankitpriyarup/godot-tools/tree/lsp-client<br>
- Mentor Client Working Branch: https://github.com/GodotExplorer/godot-tools/tree/lsp-client

## Progress:
Since my first report on GDScript Language Server, there have been a couple of improvements mostly in the markdown Documentation System.

- Better doc item indexing which parses entire class structure and stores it on a index.json file within markdown documentation directory for faster lookups.
- Hyperlink support in markdown docs such that by clicking on any link (Class or Method name) within the doc it will simply open that class or method.
- Visual improvements in markdown doc such as better spacing, indentation & paragraph shifts. Support for bold, italic and underline.
- Autocompletion for some methods also had an issue with it's insert text bracket placement which has been now resolved.
- Rename symbol feature from before had a huge drawback i.e. it is incapable of renaming symbols found within different classes searching and replacing it won't be an efficient solution. GDScript is a dynamic typed language so it is hard to track references for symbols. So it's better to not implement this feature as it may cause bugs randomly. I suggest you use search and replace to do this kind of operations manually to avoid errors. Previous unfinished code can be found here ()

We are currently testing the framework on larger open source GDScript projects. Bugs are regularly being tracked at (https://github.com/ankitpriyarup/godot/issues) Any feedbacks and issues are welcomed, please feel free to put it on the Github issues.

## Coming Up Next:
Our major task for now is fixing bugs within current implementation and merging them with Godot master. Later on we are also planning to port it to more popular editors like Atom and Emacs.