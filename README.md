![desktop](https://raw.githubusercontent.com/abapst/blackbird/main/.github/images/desktop.jpg)

# Blackbird

<img align="right" src="https://raw.githubusercontent.com/abapst/blackbird/main/.github/images/blackbird_animation.gif" width="300" height="550" />

My personal rainmeter setup.
Inspired by the look of the amazing [Enigma](https://github.com/kaelri/enigma) by Kaelri, but all code and resources belong to me.

I wasn't satisfied with a lot of the jerky-looking animated meters out there and wanted something smoother looking so I developed this. The CPU usage is not great due to the refresh rate of the histogram skins and I probably would not run this on a laptop.

## Requirements

You need to install [Rainmeter](https://www.rainmeter.net/) for Windows 10.

If you want to use the cpu_temperature meter, you will also need to install
the Core Temp tool and run it in the background, located [here](https://www.alcpu.com/CoreTemp/).

![core_temperature](https://raw.githubusercontent.com/abapst/blackbird/main/.github/images/core_temperature.jpg)

## Installation

1. Clone repo into your Documents\Rainmeter\Skins folder.
2. Open up Rainmeter, load the skins under 'blackbird' and rearrange them however you wish.

Note: for the smooth histograms to work, you need to refresh the skins once after loading because the lua script generates automatic skins that need to be reloaded to function properly. Haven't figured out a way around this yet.
