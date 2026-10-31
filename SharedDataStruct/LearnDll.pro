TEMPLATE = subdirs
SUBDIRS += writer reader app

app.depends = writer reader
