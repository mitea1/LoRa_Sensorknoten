/**
 * @file uBloxConfig.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */

#ifndef UBLOXCONFIG_H_
#define UBLOXCONFIG_H_

/**
 * uBlox Modes. Modes define Sensor functionality
 */
enum uBLOX_MODE{
	uBLOX_MODE_1,//!< uBLOX_MODE_1
	uBLOX_MODE_2,//!< uBLOX_MODE_2
	uBLOX_MODE_3,//!< uBLOX_MODE_3
	uBLOX_MODE_4,//!< uBLOX_MODE_4
	uBLOX_MODE_5 //!< uBLOX_MODE_5
};

/**
 * @class uBloxConfig
 * @brief A configuration container for the uBlox.
 * All its configuration values are stored an held inside
 * this Class. Depending on the uBLOX_MODE it sets all the configuration values.
 */
class uBloxConfig {
public:
	uBloxConfig();
	virtual ~uBloxConfig();

	/**
	 * @brief Generates a configuration according to the chosen uBLOX_MODE
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(uBLOX_MODE);
};

#endif /* UBLOXCONFIG_H_ */
