# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Flappy_bird_udacity_config = debug

else ifeq ($(config),release)
  Flappy_bird_udacity_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := Flappy-bird-udacity

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Flappy-bird-udacity:
ifneq (,$(Flappy_bird_udacity_config))
	@echo "==== Building Flappy-bird-udacity ($(Flappy_bird_udacity_config)) ===="
	@${MAKE} --no-print-directory -C . -f Flappy-bird-udacity.make config=$(Flappy_bird_udacity_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f Flappy-bird-udacity.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Flappy-bird-udacity"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"