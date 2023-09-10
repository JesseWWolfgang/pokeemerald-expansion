# MAKEFLAGS += --no-print-directory
TILESETS_DIR := data/tilesets
PORYTILES_DIR := data/tilesets/porytiles
PORYTILES_BINARY := tools/pory/porytiles
PORYARGS := -assign-explore-cutoff=4 -assign-algorithm=bfs -prune-branches=0

PAL_NUMS := 00 01 02 03 04 05 06 07 08 09 10 11 12
PAL_NAMES := $(PAL_NUMS:%=palettes/%.pal)
DEST_NAMES := tiles.png metatiles.bin metatile_attributes.bin $(PAL_NAMES)

PRIMARY_TILESET_NAMES := porytiles_test porytiles_test2
SECONDARY_TILESET_NAMES := porytiles_test_secondary liberty_garden

PRIMARY_TILESET_PATHS := $(patsubst %, $(TILESETS_DIR)/primary/%/, $(PRIMARY_TILESET_NAMES))
PRIMARY_TARGETS := $(foreach P, $(PRIMARY_TILESET_PATHS), $(addprefix $(P), $(DEST_NAMES)))

SECONDARY_TILESET_PATHS := $(patsubst %, $(TILESETS_DIR)/secondary/%/, $(SECONDARY_TILESET_NAMES))
SECONDARY_TARGETS := $(foreach P, $(SECONDARY_TILESET_PATHS), $(addprefix $(P), $(DEST_NAMES)))

.PHONY: porytilesall buildprimary buildsecondary
porytilesall: buildprimary buildsecondary

buildprimary: $(PRIMARY_TARGETS)
buildsecondary: $(SECONDARY_TARGETS)

# Primary

$(addprefix $(TILESETS_DIR)/primary/porytiles_test/, $(DEST_NAMES)) &: $(shell find $(PORYTILES_DIR)/primary/porytiles_test)
	$(PORYTILES_BINARY) compile-primary ${PORYARGS} -o $(TILESETS_DIR)/primary/porytiles_test $(PORYTILES_DIR)/primary/porytiles_test

$(addprefix $(TILESETS_DIR)/primary/porytiles_test2/, $(DEST_NAMES)) &: $(shell find $(PORYTILES_DIR)/primary/porytiles_test2)
	$(PORYTILES_BINARY) compile-primary ${PORYARGS} -o $(TILESETS_DIR)/primary/porytiles_test2 $(PORYTILES_DIR)/primary/porytiles_test2

# Secondary

$(addprefix $(TILESETS_DIR)/secondary/porytiles_test_secondary/, $(DEST_NAMES)) &: $(shell find $(PORYTILES_DIR)/secondary/porytiles_test_secondary)
	$(PORYTILES_BINARY) compile-secondary ${PORYARGS} -o $(TILESETS_DIR)/secondary/porytiles_test_secondary $(PORYTILES_DIR)/secondary/porytiles_test_secondary $(PORYTILES_DIR)/primary/porytiles_test

$(addprefix $(TILESETS_DIR)/secondary/liberty_garden/, $(DEST_NAMES)) &: $(shell find $(PORYTILES_DIR)/secondary/liberty_garden)
	$(PORYTILES_BINARY) compile-secondary ${PORYARGS} -o $(TILESETS_DIR)/secondary/liberty_garden $(PORYTILES_DIR)/secondary/liberty_garden $(PORYTILES_DIR)/primary/porytiles_test