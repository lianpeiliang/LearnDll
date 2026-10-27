TEMPLATE = subdirs

SUBDIRS += logger business app

# Build B first, then A, and finally the application.
business.depends = logger
app.depends = business
