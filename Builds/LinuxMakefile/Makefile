#------------------------------------------------------------------------------
# Automatically generated Makefile emulating Projucer 8.0.0 output.
#------------------------------------------------------------------------------

ifeq ($(origin CONFIG), undefined)
  CONFIG := Release
endif

JUCE_ROOT                := ../../JUCE
PROJECT_ROOT             := ../..
BUILD_DIR                := build/$(CONFIG)
OBJ_DIR                  := $(BUILD_DIR)/obj
TARGET_NAME              := StrudelVST
TARGET                   := $(BUILD_DIR)/$(TARGET_NAME)
PKGCONFIG_PACKAGES       := gtk+-3.0 webkit2gtk-4.0 freetype2 fontconfig alsa

CXX                      := g++
CC                       := gcc
STRIP                    := strip
AR                       := ar
PKGCONFIG                := pkg-config

JUCE_PKGCONFIG_CFLAGS    := $(shell $(PKGCONFIG) --cflags $(PKGCONFIG_PACKAGES))
JUCE_PKGCONFIG_LIBS      := $(shell $(PKGCONFIG) --libs $(PKGCONFIG_PACKAGES))

MODULE_INCLUDE_PATH      := -I$(JUCE_ROOT)/modules
PROJECT_INCLUDE_PATHS    := -I$(PROJECT_ROOT)/Source -I./JuceLibraryCode

BASE_CXXFLAGS            := -std=c++20 -fPIC -pthread -fvisibility=hidden -Wall -Wextra -Wno-ignored-qualifiers \
                             -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 \
                             -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 \
                             -DJucePlugin_Build_Unity=0 -DJUCE_MODAL_LOOPS_PERMITTED=1 -DJUCE_STANDALONE_APPLICATION=1 \
                             -DJUCE_WEB_BROWSER=1 $(MODULE_INCLUDE_PATH) $(PROJECT_INCLUDE_PATHS) $(JUCE_PKGCONFIG_CFLAGS)

BASE_CFLAGS              := -std=c11 -fPIC -pthread -fvisibility=hidden -Wall -Wextra -Wno-ignored-qualifiers \
                             -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 \
                             -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 \
                             -DJucePlugin_Build_Unity=0 -DJUCE_MODAL_LOOPS_PERMITTED=1 -DJUCE_STANDALONE_APPLICATION=1 \
                             -DJUCE_WEB_BROWSER=1 $(MODULE_INCLUDE_PATH) $(PROJECT_INCLUDE_PATHS) $(JUCE_PKGCONFIG_CFLAGS)

BASE_LDFLAGS             := -pthread -ldl -lrt

ifeq ($(CONFIG),Debug)
  CXXFLAGS               := $(BASE_CXXFLAGS) -O0 -g -DDEBUG=1 -DJUCE_DEBUG=1
  CFLAGS                 := $(BASE_CFLAGS) -O0 -g -DDEBUG=1 -DJUCE_DEBUG=1
  LDFLAGS                := $(BASE_LDFLAGS)
else
  CXXFLAGS               := $(BASE_CXXFLAGS) -O3 -DNDEBUG=1
  CFLAGS                 := $(BASE_CFLAGS) -O3 -DNDEBUG=1
  LDFLAGS                := $(BASE_LDFLAGS)
endif

LDFLAGS                  += $(JUCE_PKGCONFIG_LIBS)

SOURCE_FILES := \
  PluginProcessor.cpp \
  PluginEditor.cpp \
  include_juce_audio_basics.cpp \
  include_juce_audio_devices.cpp \
  include_juce_audio_formats.cpp \
  include_juce_audio_plugin_client.cpp \
  include_juce_audio_processors.cpp \
  include_juce_audio_processors_headless.cpp \
  include_juce_audio_utils.cpp \
  include_juce_core.cpp \
  include_juce_data_structures.cpp \
  include_juce_events.cpp \
  include_juce_graphics.cpp \
  include_juce_gui_basics.cpp \
  include_juce_gui_basics_2.cpp \
  include_juce_gui_basics_3.cpp \
  include_juce_gui_basics_4.cpp \
  include_juce_gui_basics_5.cpp \
  include_juce_gui_extra.cpp

SHEENBIDI_SOURCE := JuceLibraryCode/include_juce_graphics_Sheenbidi.c

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCE_FILES:.cpp=.o))
OBJECTS += $(OBJ_DIR)/juce_graphics_Sheenbidi.o
DEPFILES := $(OBJECTS:.o=.d)

.PHONY: all clean strip

all: $(TARGET)
	@echo "Built $(TARGET)"

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(PROJECT_ROOT)/Source/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: JuceLibraryCode/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/juce_graphics_Sheenbidi.o: $(SHEENBIDI_SOURCE)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

strip: $(TARGET)
	$(STRIP) $(TARGET)

clean:
	rm -rf build

-include $(DEPFILES)
