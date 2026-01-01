#pragma once

#include "JuceHeader.h"

class StrudelVSTAudioProcessor;

class StrudelVSTAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  explicit StrudelVSTAudioProcessorEditor(StrudelVSTAudioProcessor &);
  ~StrudelVSTAudioProcessorEditor() override = default;

  void resized() override;

private:
  StrudelVSTAudioProcessor &processor;
  juce::WebBrowserComponent webView;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StrudelVSTAudioProcessorEditor)
};
