#pragma once

#include "JuceHeader.h"

class StrudelVSTAudioProcessor : public juce::AudioProcessor {
public:
  StrudelVSTAudioProcessor();
  ~StrudelVSTAudioProcessor() override = default;

  //==============================================================================
  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
  bool isBusesLayoutSupported(const BusesLayout &layouts) const override;
#endif

  void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;
  using AudioProcessor::processBlock;

  //==============================================================================
  juce::AudioProcessorEditor *createEditor() override;
  bool hasEditor() const override { return true; }

  //==============================================================================
  const juce::String getName() const override { return JucePlugin_Name; }

  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool isMidiEffect() const override;
  double getTailLengthSeconds() const override { return 0.0; }

  //==============================================================================
  int getNumPrograms() override { return 1; }
  int getCurrentProgram() override { return 0; }
  void setCurrentProgram(int index) override { juce::ignoreUnused(index); }
  const juce::String getProgramName(int index) override {
    juce::ignoreUnused(index);
    return {};
  }
  void changeProgramName(int index, const juce::String &newName) override {
    juce::ignoreUnused(index, newName);
  }

  //==============================================================================
  void getStateInformation(juce::MemoryBlock &destData) override;
  void setStateInformation(const void *data, int sizeInBytes) override;

  const juce::String &getStartupUrl() const noexcept { return startupUrl; }

private:
  static juce::String createStrudelEmbedDataUrl();
  const juce::String startupUrl{createStrudelEmbedDataUrl()};

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StrudelVSTAudioProcessor)
};
