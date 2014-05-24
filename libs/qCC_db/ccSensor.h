//##########################################################################
//#                                                                        #
//#                            CLOUDCOMPARE                                #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef CC_SENSOR_HEADER
#define CC_SENSOR_HEADER

//Local
#include "ccHObject.h"
#include "ccIndexedTransformationBuffer.h"

//! Sensor types
enum CC_SENSOR_TYPE {	UNKNOWN_SENSOR,
						GROUND_BASED_LIDAR,
};

//! Generic sensor interface
/** New sensor framework now relies on separate positions (stored
	in a buffer) as generated by a GPS/IMU. This way, sensor objects
	only contains intrinsic parameters. They are also associated
	to a 'rigid transformation' (e.g. a rigid mechanical link between
	the sensor 'optical' center and the GPS/IMU center position).
**/
#ifdef QCC_DB_USE_AS_DLL
#include "qCC_db.h"
class QCC_DB_LIB_API ccSensor : public ccHObject
#else
class ccSensor : public ccHObject
#endif
{
public:

	//! Default constructor
	ccSensor(QString name);

    //inherited from ccHObject
    virtual CC_CLASS_ENUM getClassID() const { return CC_TYPES::SENSOR; };
	virtual bool isSerializable() const { return true; }

	//! Returns the sensor type
	/** Should be re-implemented by sub-classes
        \return the sensor type
	**/
	virtual CC_SENSOR_TYPE getType() const { return UNKNOWN_SENSOR; }

	//! Returns the "visibility type" of a point
	/** Precise definition of point's visibility can be found in Daniel Girardeau-Montaut's
		PhD manuscript (Chapter 2, section 2-3-3). In fact it can be anything, assuming that
		a point that is not POINT_VISIBLE won't be compared during a point-to-cloud distance
		computation process.
		\deprecated This method is deprecated and should be ignored.
		\param P a 3D point
		\return the visibility of the point
	**/
	virtual inline uchar checkVisibility(const CCVector3& P) const { return POINT_VISIBLE; }

	//! Returns associated positions
	ccIndexedTransformationBuffer* getPositions()  { return m_posBuffer; }

	//! Sets associated positions
	void setPositions(ccIndexedTransformationBuffer* positions)  { m_posBuffer = positions; }

	//! Adds a new position (shortcut)
	/** \warning: may be slow as this method may sort the positions
		after each call (if the new index is lower than the last one pushed)
	**/
	bool addPosition(ccGLMatrix& trans, double index);

	//! Returns the absolute transformation between the world and the "optical" center (shortcut)
	/** Absolute transformation corresponds to the rigid transformation
		multiplied by the associated transformation interpolated at the given index.
	**/
	bool getAbsoluteTransformation(ccIndexedTransformation& trans, double index) const;

	//! Gets currently active absolute transformation
	bool getActiveAbsoluteTransformation(ccIndexedTransformation& trans) const;
	
	//! Gets currently active absolute position
	bool getActiveAbsoluteCenter(CCVector3& vec) const;

	//! Gets currently active rotation matrix (without translation)
	bool getActiveAbsoluteRotation(ccGLMatrix& rotation) const;

	//! Sets the rigid transformation between this sensor and its associated positions
	/** Rigid transformation goes from the sensor position(s) to the sensor "optical" center.
	**/
	virtual void setRigidTransformation(const ccGLMatrix& mat) { m_rigidTransformation = mat; }

	//! Returns the rigid transformation between this sensor and its associated positions
	virtual ccGLMatrix& getRigidTransformation() { return m_rigidTransformation; }

	//! Returns the rigid transformation between this sensor and its associated positions (const version)
	virtual const ccGLMatrix& getRigidTransformation() const { return m_rigidTransformation; }

	//! Gets index boundaries (shortcut)
	void getIndexBounds(double& minIndex, double& maxIndex) const;

	//! Sets currently active index (displayed position, etc.)
	double getActiveIndex() const { return m_activeIndex; }

	//! Sets currently active index (displayed position, etc.)
	void setActiveIndex(double index) { m_activeIndex = index; }

	//! Sets the sensor graphic representation scale
	void setGraphicScale(PointCoordinateType scale) { m_scale = scale; }

    //! Returns the sensor graphic representation scale
	PointCoordinateType getGraphicScale() const { return m_scale; }

protected:

    //inherited from ccHObject
	virtual bool toFile_MeOnly(QFile& out) const;
	virtual bool fromFile_MeOnly(QFile& in, short dataVersion, int flags);

	//inherited from ccHObject
    virtual void applyGLTransformation(const ccGLMatrix& trans);

	//! Positions buffer (optional)
	ccIndexedTransformationBuffer* m_posBuffer;

	//! Rigid transformation between this sensor and its associated positions
	/** The transformation goes from the sensor position(s) to the sensor "optical" center.
	**/
    ccGLMatrix m_rigidTransformation;

	//! Active index (for displayed position, etc.)
	double m_activeIndex;

	//! Color of the sensor
	/**	Default color is green. 
	**/
	Vector3Tpl<colorType> m_color;

	//! Sensor graphic representation scale
    PointCoordinateType m_scale;
};

#endif //CC_SENSOR_HEADER
