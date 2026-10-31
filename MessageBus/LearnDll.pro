TEMPLATE = subdirs

SUBDIRS += bus login notice app

login.depends = bus
notice.depends = bus
app.depends = login notice
