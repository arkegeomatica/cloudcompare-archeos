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

#ifndef CC_IMAGE_HEADER
#define CC_IMAGE_HEADER

//Local
#include "qCC_db.h"
#include "ccHObject.h"

//Qt
#include <QImage>
#include <QString>

class ccGenericGLDisplay;
class ccCameraSensor;

//! Generic image
class QCC_DB_LIB_API ccImage : public ccHObject
{
public:

	//! Default constructor
	ccImage();

	//! Constructor from QImage
	ccImage(const QImage& image, const QString& name = QString("unknown"));

	//inherited methods (ccHObject)
	virtual bool isSerializable() const { return true; }

	//! Returns unique class ID
	virtual CC_CLASS_ENUM getClassID() const { return CC_TYPES::IMAGE; }

	//! Loads image from file
	/** \param filename image filename
		\param error a human readable description of what went wrong (if method fails)
		\return success
	**/
	bool load(const QString& filename, QString& error);

	//! Returns image data
	inline QImage& data() { return m_image; }
	//! Returns image data (const version)
	inline const QImage& data() const { return m_image; }

	//! Sets image data
	void setData(const QImage& image);

	//! Returns image width
	inline unsigned getW() const { return m_width; }

	//! Returns image height
	inline unsigned getH() const { return m_height; }

	//! Sets image texture transparency
	void setAlpha(float value);

	//! Returns image texture transparency
	inline float getAlpha() const { return m_texAlpha; }

	//! Manually sets aspect ratio
	void setAspectRatio(float ar) { m_aspectRatio = ar; }

	//! Returns aspect ratio
	inline float getAspectRatio() const { return m_aspectRatio; }

	//! Sets associated sensor
	void setAssociatedSensor(ccCameraSensor* sensor);

	//! Returns associated sensor
	ccCameraSensor* getAssociatedSensor() { return m_associatedSensor; }

	//! Returns associated sensor (const version)
	const ccCameraSensor* getAssociatedSensor() const { return m_associatedSensor; }

protected:

	//inherited from ccHObject
	virtual void drawMeOnly(CC_DRAW_CONTEXT& context);
	virtual void onDeletionOf(const ccHObject* obj);
	virtual bool toFile_MeOnly(QFile& out) const;
	virtual bool fromFile_MeOnly(QFile& in, short dataVersion, int flags);

	//! Unbinds texture from currently associated GL context
	virtual bool unbindTexture();

	//! Binds texture to a GL context (and creates texture if necessary)
	/** \param win 3D display to which to bind the texture
		\param pow2Texture whether a texture with power of 2 dimensions is requested (OpenGL version < 2.0)
		\return success
	**/
	virtual bool bindToGlTexture(ccGenericGLDisplay* win, bool pow2Texture = false);

	//! Updates aspect ratio
	void updateAspectRatio();

	//! Image width (in pixels)
	unsigned m_width;
	//! Image height (in pixels)
	unsigned m_height;

	//! Aspect ratio w/h
	/** Default is m_width/m_height.
		Should be changed if pixels are not square.
	**/
	float m_aspectRatio;

	//! Texture coordinate (width) of bottom-right pixel
	float m_texU;
	//! Texture coordinate (height) of bottom-right pixel
	float m_texV;

	//! Texture transparency
	float m_texAlpha;

	//! Texture GL ID
	unsigned m_textureID;

	//! Currently bound GL window
	ccGenericGLDisplay* m_boundWin;

	//! Image data
	QImage m_image;

	//! Associated sensor
	ccCameraSensor* m_associatedSensor;
};

#endif //CC_IMAGE_HEADER
