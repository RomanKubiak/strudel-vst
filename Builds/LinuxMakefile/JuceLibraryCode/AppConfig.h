#pragma once

//==============================================================================
// Auto-generated configuration file emulating the output of Projucer 8.0.0.
//==============================================================================

#define JUCE_APP_CONFIG_H_INCLUDED 1
#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED 1

//------------------------------------------------------------------------------
// Global JUCE options
//------------------------------------------------------------------------------
#define JUCE_USE_DARK_SPLASH_SCREEN 0
#define JUCE_STRICT_REFCOUNTEDPOINTER 0
#define JUCE_MODAL_LOOPS_PERMITTED 1
#define JUCE_STANDALONE_APPLICATION 1

//------------------------------------------------------------------------------
// JUCE module availability
//------------------------------------------------------------------------------
#define JUCE_MODULE_AVAILABLE_juce_audio_basics 1
#define JUCE_MODULE_AVAILABLE_juce_audio_devices 1
#define JUCE_MODULE_AVAILABLE_juce_audio_formats 1
#define JUCE_MODULE_AVAILABLE_juce_audio_plugin_client 1
#define JUCE_MODULE_AVAILABLE_juce_audio_processors 1
#define JUCE_MODULE_AVAILABLE_juce_audio_processors_headless 1
#define JUCE_MODULE_AVAILABLE_juce_audio_utils 1
#define JUCE_MODULE_AVAILABLE_juce_core 1
#define JUCE_MODULE_AVAILABLE_juce_data_structures 1
#define JUCE_MODULE_AVAILABLE_juce_events 1
#define JUCE_MODULE_AVAILABLE_juce_graphics 1
#define JUCE_MODULE_AVAILABLE_juce_gui_basics 1
#define JUCE_MODULE_AVAILABLE_juce_gui_extra 1

//------------------------------------------------------------------------------
// Module settings
//------------------------------------------------------------------------------
#define JUCE_WEB_BROWSER 1
#undef JUCE_USE_CURL
#define JUCE_USE_CURL 0
#define JUCE_ASIO 0
#define JUCE_WASAPI 0
#define JUCE_DIRECTSOUND 0
#define JUCE_ALSA 1
#define JUCE_JACK 0
#define JUCE_BELA 0
#define JUCE_USE_ANDROID_OPENSLES 0
#define JUCE_USE_ANDROID_OBOE 0
#define JUCE_USE_WINRT_MIDI 0
#define JUCE_VST3_CAN_REPLACE_VST2 0

//------------------------------------------------------------------------------
// Plugin characteristics (mirrors StrudelVST.jucer)
//------------------------------------------------------------------------------
#define JucePlugin_Build_VST 0
#define JucePlugin_Build_VST3 0
#define JucePlugin_Build_AU 0
#define JucePlugin_Build_AUv3 0
#define JucePlugin_Build_RTAS 0
#define JucePlugin_Build_AAX 0
#define JucePlugin_Build_Unity 0
#define JucePlugin_Build_Standalone 1

#define JucePlugin_Name "StrudelVST"
#define JucePlugin_Desc "Web-powered JUCE plugin"
#define JucePlugin_Manufacturer "Strudel"
#define JucePlugin_ManufacturerCode 'Stru'
#define JucePlugin_PluginCode 'StWd'
#define JucePlugin_Version 0x00000100
#define JucePlugin_VersionString "0.1.0"
#define JucePlugin_IsSynth 0
#define JucePlugin_WantsMidiInput 0
#define JucePlugin_ProducesMidiOutput 0
#define JucePlugin_IsMidiEffect 0
#define JucePlugin_EditorRequiresKeyboardFocus 0
#define JucePlugin_TailLengthSeconds 0.0
#define JucePlugin_ChannelConfigs "{Stereo,Stereo}"
#define JucePlugin_UsesSideChain 0
#define JucePlugin_MaxNumInputChannels 2
#define JucePlugin_MaxNumOutputChannels 2
#define JucePlugin_PreferredChannelConfigurations 0
