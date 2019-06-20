# Using the templates

This is a basic template for Visual Studio Code on Windows. It uses MSBuild to build a simple
C++ project.

> Note: You have to maintain the project file manually. It is created with the single `main.cpp`
> file in it.

## To copy the template:

```
xcopy /s/i/v/q _template_ {project_name}
```

## Or run the CMD script

This creates a new project in the folder of the given name.

```
_new_project.cmd {new_project_name}
```