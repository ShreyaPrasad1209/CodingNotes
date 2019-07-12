# GSoC Project Report 1
**Project Name:** GDScript Language Server<br>
**Student:** Ankit Priyarup ([@ankitpriyarup](https://github.com/ankitpriyarup))<br>
**Mentors:** Geequlim ([@geequlim](https://github.com/geequlim)) and Jiacheng Lu ([@jason0214](https://github.com/jason0214))<br>
**Repositories:** <br>
- Student Server Working Branch: https://github.com/ankitpriyarup/godot/tree/lsp<br>
- Mentor Server Working Branch: https://github.com/GodotExplorer/godot/tree/gdscript-lsp<br>
- Student Client Working Branch: https://github.com/ankitpriyarup/godot-tools/tree/lsp-client<br>
- Mentor Client Working Branch: https://github.com/GodotExplorer/godot-tools/tree/lsp-client

## What's the project?:
Integrated script editor in Godot lacks features found in editors like VS Code, Sublime, Emacs, etc. These editors are also more popular among developers and therefore are better to switch for usability. However, to implement core functionalities such as - Diagnosis, Registering custom symbols, jump to definition, etc a Language Server structure has to be adopted. For example, the client (say vs code) will communicate the godot language server to give desired result.

Microsoft's Language Server Protocol (LSP) is flexible and powerful to implement these functionalities. It also supports many editors - VS Code, Atom, Sublime, etc. Hence, instead of writing complete extensions for each editor (client) using LSP servers can be reused while the client which is an editor extension has to be only re-written.

## How it's like to work with Godot:
I had a wonderful time coding with the fantastic and helpful community at Godot. I am mentored by jason0214 and geequlim, jason0214 is very responsible as he always points out my flaws and potential weekness from the regular code review. geequlim is very active to the project and I always get to learn a lot from his commits. Besides that it's an amazing experience to talk to other students and share whatever we learned. Writing clear and well structured code to meet standards, and making sure your changes does not break anything else was a truly educational experience.

I have the freedom to arrange my time and set my own plan, there's no pressure at all. Mentors encorage me to be as creative as I can and I'm free to choose how to finish my work. Summing it all up working at Godot has been a really great experience for me.

## Current Progress:
I started off by getting familliar with the existing godot tool for vscode, improving existing 'configuration' and 'grammers', we had to remove most of client side code because we wanted to rely on LSP server (Godot) for most of the task for two reasons.<br>
- To make Client smaller and easy to port into other editors such as Atom & Emacs.
- To reuse existing implementation of built-in GDScript editor and reduce duplicacy.

The [LSP Specification](https://microsoft.github.io/language-server-protocol/specification) is based on an extended version of JSON RPC which can be basically used for sending notifications, requests and responses. For example: VSCode (Client) will first send a notification that the opened file is GDScript by matching it's extension then the Language Server will be connected. Client then again sends a notification defining what all capabilities it can provide. Rest most of the tasks can be broken down into request-response structure, client requests something server responds with a result.

### 1) Diagnostics:
An Extended GDScript Parser is created inheriting from the original GDScript Parser with aim to carry specialized parsing task for LSP. Everytime there's a change detected by the LSP Server from client and diagnostics are updated i.e. Errors and warnings along with their relevant informations such as Range (line and column number for both start and end) and message are stored in a map for faster lookups.

### 2) Code Completion:
Existing complete_code implementation from built-in code editor is reused however godot also matches written code continuiusly to filter out while in LSP at the beginning complete list of all items is sent to client by the server. Which then internally handles matching part, infact client's handles it better then builtin editor. In the below example writing 'texture' in LSP editor matches not only initial characters but also present anywhere within the item.

![Comparison of LSP editor from builtin](https://i.ibb.co/D1RYvLk/gdscript-lsp-completion-comparison.png)<br>

### 3) Symbol Cache Pool:
To provide lookup functionalities such as - Function Assist, Hover Provider, Symbol Resolve and Go to definition a symbol pool to cache all of the symbols (both native and script symbols) The cache pool is filled at the startup by parsing all scripts in the workspace for script symbols and loading native symbols from DocData.

![Symbol Cache Pool](https://i.ibb.co/k502DKm/symbol-pool.gif)<br>

### 4) Documentation Provider:
To provide quick lookup at a class documentation, entire Godot docs is converted and dumped into system files which will can be directly opened by the editors. A simple Regex parser is capable of parsing the class name on 'View Symbol Documentation' incase parsed symbol isn't recognised list of all the symbols will be shown.

![Documentation Provider](https://i.ibb.co/dDN4rYh/documentation-provider.gif)<br>

Besides these other features such as Rename symbol is also implemented, it first finds out the position of symbol definition and then the code replaces previous name to newly specified name from the position of definition till it's scope (by checking the indentation).

![Rename Symbol](https://i.ibb.co/0MDm7RT/rename.gif)<br>

## Future Steps:
For the remaining of coding period, we'll be focusing on:
- CodeLens support for disable warnings and show slots informations connected nodes.
- Adding a way to auto insert the signal connection code via the LSP.
- Fixing bugs in current implementation and merging them with Godot master.
- Porting client to more popular editors like Atom and Emacs.