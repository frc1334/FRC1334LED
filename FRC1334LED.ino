#include "FastLED.h"

#define NUM_LEDS 36
// Arduino pin used for Data
#define DATA 6 
// Data pin for alliance selection
#define ALLIANCE 2
// Define the array of leds
CRGB leds[NUM_LEDS];
// Colour for alliance based colours.
CRGB::HTMLColorCode COLOUR;
int alliance;
void setup()
{
	FastLED.addLeds<WS2812B, DATA, GRB>(leds, NUM_LEDS);
	alliance = digitalRead(ALLIANCE);


}

void loop()
{
	switch (alliance)
	{
	case LOW:
		COLOUR = CRGB::Red;
		break;
	case HIGH:
	default:
		COLOUR = CRGB::Blue;
		break;
	}
	for (int i = 0; i < NUM_LEDS; i++)
	{
		leds[i] = COLOUR;
		FastLED.show();
		delay(500);
	}
}
