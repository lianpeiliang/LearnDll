TEMPLATE = subdirs
SUBDIRS += download business app

# Build the download library B, then business library A, then the app.
business.depends = download
app.depends = business
