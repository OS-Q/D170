
#ifndef TWITTER_H
#define TWITTER_H

#include <inttypes.h>
#if defined(__AVR__) 
#include <avr/pgmspace.h>
#endif

#if defined(ARDUINO) && ARDUINO > 18   // Arduino 0019 or later
#include <SPI.h>
#endif
#include <W5500.h>
#if defined(ARDUINO) && ARDUINO < 100  // earlier than Arduino 1.0
#include <EthernetDNS.h>
#endif

class Twitter
{
private:
	uint8_t parseStatus;
	int statusCode;
	const char *token;
#if defined(ARDUINO) && ARDUINO < 100
	Client client;
#else
	EthernetClient client;
#endif
public:
	Twitter(const char *user_and_passwd);
	
	bool post(const char *msg);
	bool checkStatus(Print *debug = NULL);
	int  wait(Print *debug = NULL);
	int  status(void) { return statusCode; }
};

#endif	//TWITTER_H
