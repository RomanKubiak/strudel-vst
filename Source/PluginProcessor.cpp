#include "PluginProcessor.h"
#include "PluginEditor.h"

namespace {

juce::String createStrudelEmbedHtml() {
  return R"(<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <style>
      html, body, iframe {
        width: 100%;
        height: 100%;
        border: 0;
        margin: 0;
        padding: 0;
        background-color: #101014;
      }
    </style>
  </head>
  <body>
    <iframe
      src="https://strudel.cc/?standalone=1"
      allow="clipboard-read; clipboard-write; microphone; autoplay"
      allowfullscreen
    ></iframe>
  </body>
</html>)";
}

} // namespace

juce::String StrudelVSTAudioProcessor::createStrudelEmbedDataUrl() {
  const auto html = createStrudelEmbedHtml();
  const auto *raw = html.toRawUTF8();
  const auto base64 =
      juce::Base64::toBase64(raw, static_cast<int>(html.getNumBytesAsUTF8()));
  return "data:text/html;charset=utf-8;base64," + base64;
}

StrudelVSTAudioProcessor::StrudelVSTAudioProcessor()
    : juce::AudioProcessor(
          BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
              .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
              .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
      ) {
}

void StrudelVSTAudioProcessor::prepareToPlay(double sampleRate,
                                             int samplesPerBlock) {
  juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void StrudelVSTAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool StrudelVSTAudioProcessor::isBusesLayoutSupported(
    const BusesLayout &layouts) const {
#if JucePlugin_IsMidiEffect
  juce::ignoreUnused(layouts);
  return true;
#else
  auto mainOutput = layouts.getMainOutputChannelSet();

  if (mainOutput != juce::AudioChannelSet::mono() &&
      mainOutput != juce::AudioChannelSet::stereo())
    return false;

#if !JucePlugin_IsSynth
  auto mainInput = layouts.getMainInputChannelSet();
  if (mainInput != juce::AudioChannelSet::mono() &&
      mainInput != juce::AudioChannelSet::stereo())
    return false;
#endif

  return true;
#endif
}
#endif

void StrudelVSTAudioProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                            juce::MidiBuffer &midiMessages) {
  juce::ScopedNoDenormals noDenormals;
  for (auto channel = 0; channel < buffer.getNumChannels(); ++channel)
    buffer.clear(channel, 0, buffer.getNumSamples());

  midiMessages.clear();
}

bool StrudelVSTAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool StrudelVSTAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool StrudelVSTAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

juce::AudioProcessorEditor *StrudelVSTAudioProcessor::createEditor() {
  return new StrudelVSTAudioProcessorEditor(*this);
}

void StrudelVSTAudioProcessor::getStateInformation(
    juce::MemoryBlock &destData) {
  juce::ignoreUnused(destData);
}

void StrudelVSTAudioProcessor::setStateInformation(const void *data,
                                                   int sizeInBytes) {
  juce::ignoreUnused(data, sizeInBytes);
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
  return new StrudelVSTAudioProcessor();
}
