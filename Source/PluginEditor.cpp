#include "PluginEditor.h"
#include "PluginProcessor.h"

StrudelVSTAudioProcessorEditor::StrudelVSTAudioProcessorEditor(
    StrudelVSTAudioProcessor &p)
    : juce::AudioProcessorEditor(&p), processor(p) {
#if !JUCE_WEB_BROWSER
  jassertfalse; // WebBrowserComponent requires JUCE_WEB_BROWSER to be enabled.
#endif

  setSize(1024, 600);
  addAndMakeVisible(webView);
  webView.goToURL(processor.getStartupUrl());
}

void StrudelVSTAudioProcessorEditor::resized() {
  webView.setBounds(getLocalBounds());
}
