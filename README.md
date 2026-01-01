# StrudelVST

 StrudelVST is a JUCE-based audio plug-in prototype that hosts a web experience using the `juce::WebBrowserComponent`. The project is configured for standalone testing on Linux and tracks the latest JUCE `develop` branch via a bundled Git submodule.

## Prerequisites

- Git submodules initialized:
  ```bash
  git submodule update --init --recursive
  ```
- Projucer built from the JUCE repository.
- WebKit GTK dependencies (Ubuntu/Debian example):
  ```bash
  sudo apt-get install libwebkit2gtk-4.0-dev libgtk-3-dev
  ```

## Configuring the Project

1. Open `StrudelVST.jucer` in Projucer.
2. Confirm the JUCE modules path points to the checked-out `JUCE` submodule (default is `JUCE`).
3. Save the project to generate the Linux Makefile exporter.
4. Build the generated standalone target from `Builds/LinuxMakefile`:
   ```bash
   cd Builds/LinuxMakefile
   make CONFIG=Release
   ```

## Customising the Web View

- The default startup URL is defined in `Source/PluginProcessor.h` via `startupUrl`.
- Update the value or expose a parameter before building to point to the desired web property.

## Next Steps

- Enable additional plug-in formats (VST3, LV2, etc.) from Projucer when you are ready to distribute beyond the standalone build.
- Wire the plug-in to process incoming audio/MIDI as required by your product design.
