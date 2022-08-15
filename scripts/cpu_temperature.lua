-- Copyright 2022 Aleksander Bapst

function Initialize()
	MeterName = SELF:GetOption('ControlledMeter')
	Meter = SKIN:GetMeter(MeterName)
	measure = SKIN:GetMeasure(SELF:GetOption('Msr'))
end

function Update()
	currentValue = measure:GetValue()

	if (currentValue > 70) then
		SKIN:Bang('!SetOption',MeterName,'FontColor','255,0,0,255')
	elseif (currentValue > 60) then
		SKIN:Bang('!SetOption',MeterName,'FontColor','255,80,0,255')
	else
		SKIN:Bang('!SetOption',MeterName,'FontColor','0,200,255,255')
	end

	SKIN:Bang('!SetOption',MeterName,'Text',currentValue)
end
