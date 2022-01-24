[Variables]
HideAnalogHours=1
HideAnalogMinutes=1
HideDecorativeRing=0
RingYOffset=70
RingXOffset=60

[Background]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=140

[BottomLine]
Meter=IMAGE
X=10
Y=130
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
X=#RingXOffset#
Y=#RingYOffset#
LineLength=50
LineStart=38
StartAngle=4.7124
RotationAngle=6.28
AntiAlias=1
LineColor=255, 2555, 255, 255
Solid=1

;analog minutes ring
[MeterAnalogMinutes]
Meter=ROUNDLINE
MeasureName=MeasureTimeMinutes
X=#RingXOffset#
Y=#RingYOffset#
LineLength=36
LineStart=24
StartAngle=4.7124
RotationAngle=6.28
AntiAlias=1
LineColor=255, 2555, 255, 255
Solid=1
Hidden=#HideAnalogMinutes#

;analog hours ring
[MeterAnalogHours]
Meter=ROUNDLINE
MeasureName=MeasureTimeHours
X=#RingXOffset#
Y=#RingYOffset#
LineLength=22
LineStart=10
StartAngle=4.7124
RotationAngle=6.28
AntiAlias=1
LineColor=255, 2555, 255, 255
Solid=1
Hidden=#HideAnalogHours#

;seconds ring background
[MeterAnalogBG1]
Meter=ROUNDLINE
X=#RingXOffset#
Y=#RingYOffset#
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
X=#RingXOffset#
Y=#RingYOffset#
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
X=#RingXOffset#
Y=#RingYOffset#
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
X=#RingXOffset#
Y=#RingYOffset#
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
X=#RingXOffset#
Y=#RingYOffset#
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
X=#RingXOffset#
Y=#RingYOffset#
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
X=#RingXOffset#
Y=#RingYOffset#
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
X=106
Y=-5
FontColor=255, 255, 255, 255
FontSize=46
StringAlign=LEFT
StringStyle=BOLD
FontFace=Helvetica Neue LT Std
AntiAlias=1

[MeterLine]
Meter=IMAGE
X=120
Y=#RingYOffset#
W=165
H=5
SolidColor=255, 255, 255, 200

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
X=116
Y=78
StringStyle=NORMAL
StringAlign=LEFT
FontColor=255, 255, 255, 160
FontSize=12
FontFace=Helvetica Neue LT Std
AntiAlias=1

[MeterWeekDay]
Meter=STRING
MeasureName=MeasureWeek
X=116
Y=98
W=300
StringStyle=NORMAL
StringAlign=LEFT
FontColor=255, 255, 255, 217
FontSize=12
FontFace=Helvetica Neue LT Std
AntiAlias=1