[Variables]
MeterHeight=30
MeterWidth=280
SkinHeight=140
SkinWidth=300
Gap=1
BarWidth=2
White=255,255,255,255
CPU_X=0
CPU_Y=0

[CPUBackground]
Meter=IMAGE
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=#SkinWidth#
H=#SkinHeight#
X=#CPU_X#
Y=#CPU_Y#

[CPUBottomLine]
Meter=IMAGE
X=(10+#CPU_X#)
Y=(130+#CPU_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[MeasureCore0TempColored]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\cpu_temperature.lua
Msr=MeasureCore0Temp
ControlledMeter=MeterCore0Temp

[MeasureCore1TempColored]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\cpu_temperature.lua
Msr=MeasureCore1Temp
ControlledMeter=MeterCore1Temp

[MeasureCore2TempColored]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\cpu_temperature.lua
Msr=MeasureCore2Temp
ControlledMeter=MeterCore2Temp

[MeasureCore3TempColored]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#\scripts\cpu_temperature.lua
Msr=MeasureCore3Temp
ControlledMeter=MeterCore3Temp

[MeasureTotalTDP]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Power

[MeasureClockSpeed]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=CpuSpeed

[MeasureCPUName]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=CpuName
Substitute="":"[Core Temp Tool Not Running]"

[MeasureCore0Temp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=0
Substitute="":"N/A"

[MeasureCore1Temp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=1

[MeasureCore2Temp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=2

[MeasureCore3Temp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=3

[CPUNamePrefix]
Meter=STRING
MeasureName=MeasureCPUName
X=(10+#CPU_X#)
Y=(0+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=#MainFontSizeText#
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Prefix=""

[CPUNameSuffix]
Meter=STRING
X=(90+#CPU_X#)
Y=(0+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=#MainFontSizeText#
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix=""

[TotalTDPPrefix]
Meter=STRING
X=(10+#CPU_X#)
Y=(15+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=#MainFontSizeText#
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Prefix="TDP  "

[TotalTDPSuffix]
Meter=STRING
MeasureName=MeasureTotalTDP
X=(90+#CPU_X#)
Y=(15+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=#MainFontSizeText#
StringAlign=LEFT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="W"

[ClockSpeedPrefix]
Meter=STRING
MeasureName=MeasureClockSpeed
X=(242+#CPU_X#)
Y=(15+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=#MainFontSizeText#
StringAlign=RIGHT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0

[ClockSpeedSuffix]
Meter=STRING
X=(290+#CPU_X#)
Y=(15+#CPU_Y#)
FontColor=#AccentColor2#
StringStyle=NORMAL
FontSize=#MainFontSizeText#
StringAlign=RIGHT
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="  MHz"

[MeterCore0]
Meter=ROUNDLINE
X=44
Y=80
LineLength=34
LineStart=24
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor5#
Solid=1

[MeterCore0AccentLine]
Meter=ROUNDLINE
X=44
Y=80
LineLength=34
LineStart=32
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor6#
Solid=1

[MeterCore0Temp]
Meter=STRING
X=44
Y=65
MeasureName=MeasureCore0TempColored
FontColor=#AccentColor1#
StringStyle=NORMAL
FontSize=#SecondaryFontSizeText#
StringAlign=CENTER
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="°C"

[MeterCore1]
Meter=ROUNDLINE
X=114
Y=80
LineLength=34
LineStart=24
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor5#
Solid=1

[MeterCore1AccentLine]
Meter=ROUNDLINE
X=114
Y=80
LineLength=34
LineStart=32
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor6#
Solid=1

[MeterCore1Temp]
Meter=STRING
X=114
Y=65
MeasureName=MeasureCore1TempColored
FontColor=#AccentColor1#
StringStyle=NORMAL
FontSize=#SecondaryFontSizeText#
StringAlign=CENTER
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="°C"

[MeterCore2]
Meter=ROUNDLINE
X=185
Y=80
LineLength=34
LineStart=24
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor5#
Solid=1

[MeterCore2AccentLine]
Meter=ROUNDLINE
X=185
Y=80
LineLength=34
LineStart=32
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor6#
Solid=1

[MeterCore2Temp]
Meter=STRING
X=185
Y=65
MeasureName=MeasureCore2TempColored
FontColor=#AccentColor1#
StringStyle=NORMAL
FontSize=#SecondaryFontSizeText#
StringAlign=CENTER
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="°C"

[MeterCore3]
Meter=ROUNDLINE
X=255
Y=80
LineLength=34
LineStart=24
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor5#
Solid=1

[MeterCore3AccentLine]
Meter=ROUNDLINE
X=255
Y=80
LineLength=34
LineStart=32
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor6#
Solid=1

[MeterCore3Temp]
Meter=STRING
X=255
Y=65
MeasureName=MeasureCore3TempColored
FontColor=#AccentColor1#
StringStyle=NORMAL
FontSize=#SecondaryFontSizeText#
StringAlign=CENTER
FontFace=#MainFontFace#
AntiAlias=1
Hidden=0
Postfix="°C"