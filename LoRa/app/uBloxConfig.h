/*
 * uBloxConfig.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#ifndef UBLOXCONFIG_H_
#define UBLOXCONFIG_H_

enum uBLOX_MODE{
	uBLOX_MODE_1,
	uBLOX_MODE_2,
	uBLOX_MODE_3,
	uBLOX_MODE_4,
	uBLOX_MODE_5
};
class uBloxConfig {
public:
	uBloxConfig();
	virtual ~uBloxConfig();
};

#endif /* UBLOXCONFIG_H_ */
