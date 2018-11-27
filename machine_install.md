# Machine Installation Notes
## Ubuntu 18.04 LTS

### Applications

#### Visual Studio Code

> Visual Studio Code is unable to watch the for file changes in this large workspace.

The limit can be increased to its maximum by editing `/etc/sysctl.conf` and adding this line to the end of the file:

```
fs.inotify.max_user_watches=524288
```

Temporary fix with:

```
sudo sysctl fs.inotify.max_user_watches=524288
```

-or- permanent fix with

```
echo "fs.inotify.max_user_watches=524288" >> /etc/sysctl.conf
```
