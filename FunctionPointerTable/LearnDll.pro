TEMPLATE = subdirs
SUBDIRS += logger business app
app.depends = logger business
