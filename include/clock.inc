[Variables]
HideAnalogHours=1
HideAnalogMinutes=1
HideDecorativeRing=0
RingYOffset=70
RingXOffset=60
clock_X=0
clock_Y=0

[ClockBackground]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=140
X=#clock_X#
Y=#clock_Y#

[BottomLine]
Meter=IMAGE
X=(10+#clock_X#)
Y=(130+#clock_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

;===========================================;
;ANALOG CLOCK                          Start;
;===========================================;
;This is 'The Circle', add semicolon ';' before each 
;of the following line to remove it

[MeasureTimeAnalog]
Measure=Time
AverageSize=20

[MeasureTimeSeconds]
Measure=Calc
Formula=(MeasureTimeAnalog%60)/60

[MeasureTimeMinutes]
Measure=Calc
Formula=(MeasureTimeAnalog%3600)/3600

[MeasureTimeHours]
Measure=Calc
Formula=(MeasureTimeAnalog%43200)/43200

;analog seconds ring
[MeterAnalogSeconds]
Meter=ROUNDLINE
MeasureName=MeasureTimeSeconds
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=50
LineStart=38
StartAngle=4.7124
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor4#
Solid=1

;analog minutes ring
[MeterAnalogMinutes]
Meter=ROUNDLINE
MeasureName=MeasureTimeMinutes
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=36
LineStart=24
StartAngle=4.7124
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor4#
Solid=1
Hidden=#HideAnalogMinutes#

;analog hours ring
[MeterAnalogHours]
Meter=ROUNDLINE
MeasureName=MeasureTimeHours
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=22
LineStart=10
StartAngle=4.7124
RotationAngle=6.28
AntiAlias=1
LineColor=#AccentColor4#
Solid=1
Hidden=#HideAnalogHours#

;seconds ring background
[MeterAnalogBG1]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=50
LineStart=38
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 30
Solid=1

;seconds ring border
[MeterAnalogBG2]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=50
LineStart=48
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 70
Solid=1

;minutes ring background
[MeterAnalogBG3]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=36
LineStart=24
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 30
Solid=1
Hidden=#HideAnalogMinutes#

;minutes ring border
[MeterAnalogBG4]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=36
LineStart=34
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 70
Solid=1
Hidden=#HideAnalogMinutes#

;hours ring background
[MeterAnalogBG5]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=22
LineStart=10
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 30
Solid=1
Hidden=#HideAnalogHours#

;hours ring border
[MeterAnalogBG6]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=22
LineStart=20
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 70
Solid=1
Hidden=#HideAnalogHours#

;decorative center circle
[MeterAnalogBG7]
Meter=ROUNDLINE
X=(#RingXOffset#+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
LineLength=36
LineStart=24
StartAngle=47.55
RotationAngle=6.28
AntiAlias=1
LineColor=255, 255, 255, 70
Solid=1
Hidden=#HideDecorativeRing#

;===========================================;
;ANALOG CLOCK                         Ends  ;
;===========================================;

;===========================================
;HOUR AND MINUTE
;===========================================
[MeasureTime]
Measure=Time
Format=%H:%M

[MeterTime]
MeasureName=MeasureTime
Meter=STRING
X=(106+#clock_X#)
Y=(-5+#clock_Y#)
FontColor=#AccentColor4#
FontSize=46
StringAlign=LEFT
StringStyle=BOLD
FontFace=#MainFontFace#
AntiAlias=1

[MeterLine]
Meter=IMAGE
X=(120+#clock_X#)
Y=(#RingYOffset#+#clock_Y#)
W=170
H=5
SolidColor=#AccentColor2#

;CALENDAR

[MeasureWeek]
Measure=Time
Format="%A"
;Substitute="Sunday":"Minggu","Monday":"Senin","Tuesday":"Selasa","Wednesday":"Rabu","Thursday":"Kamis","Friday":"Jumat","Saturday":"Sabtu"

[MeasureDate]
Measure=Time
Format="%B %d, %Y"
;Format="%d %B %Y"
;Substitute="January":"Januari","February":"Februari","March":"Maret","April":"April","May":"Mei","June":"Juni","July":"Juli","August":"Agustus","September":"September","October":"Oktober","November":"November","December":"Desember"

[MeterDate]
Meter=STRING
MeasureName=MeasureDate
X=(116+#clock_X#)
Y=(78+#clock_Y#)
StringStyle=NORMAL
StringAlign=LEFT
FontColor=#AccentColor2#
FontSize=12
FontFace=#MainFontFace#
AntiAlias=1

[MeterWeekDay]
Meter=STRING
MeasureName=MeasureWeek
X=(116+#clock_X#)
Y=(98+#clock_Y#)
W=300
StringStyle=BOLD
StringAlign=LEFT
FontColor=#AccentColor2#
FontSize=12
FontFace=#MainFontFace#
AntiAlias=1
