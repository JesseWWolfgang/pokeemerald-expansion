# MAKEFLAGS += --no-print-directory
METATILES_DIR := data/tilesets
PORYTILES_DIR := data/tilesets/porytiles
PORYTILES_BINARY := tools/pory/porytiles

.PHONY: all buildprimary buildsecondary
all: buildprimary buildsecondary

buildprimary:
	$(PORYTILES_BINARY) compile-primary -o $(METATILES_DIR)/primary/porytiles_test $(PORYTILES_DIR)/primary/porytiles_test

buildsecondary:
	$(PORYTILES_BINARY) compile-secondary -o $(METATILES_DIR)/secondary/porytiles_test_secondary $(PORYTILES_DIR)/secondary/porytiles_test_secondary $(PORYTILES_DIR)/primary/porytiles_test