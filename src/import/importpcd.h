/*
* Software License Agreement (BSD License)
*
* Copyright (c) 2015, Jan Hackenberg, University of Freiburg.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above
* copyright notice, this list of conditions and the following
* disclaimer in the documentation and/or other materials provided
* with the distribution.
* * Neither the name of Willow Garage, Inc. nor the names of its
* contributors may be used to endorse or promote products derived
* from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef IMPORTPCD_H
#define IMPORTPCD_H
#include <iostream>
#define PCL_NO_PRECOMPILE
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/console/time.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/features/principal_curvatures.h>
#include <pcl/io/ply_io.h>
#include "../controller.h"
#include "../method/eigenvalueestimator.h"
#include <QString>
#include <qfile.h>
#include <QTextStream>
#include <QRegExp>

#include <iostream>
#include <fstream>
#include <string>
typedef pcl::PointXYZINormal PointI;
typedef pcl::PointCloud<PointI> PointCloudI;
typedef pcl::PointCloud<pcl::PrincipalCurvatures> CurvatureCloud;

class Controller;
class ImportPCD : public QObject
{
    Q_OBJECT
    std::string _fileName;

    pcl::console::TicToc tt;

    PointCloudI::Ptr _cloud_intens;

    void
    setRGB ();

    boost::shared_ptr<Controller>
    getControl ();

    boost::weak_ptr<Controller> _control;

public:

    ImportPCD (QString _fileName);

    ImportPCD (std::string _fileName,
               boost::weak_ptr<Controller> _control);

    virtual
    ~ImportPCD ();

    PointCloudI::Ptr
    importPCD ();

    PointCloudI::Ptr
    importASC ();

    PointI
    toPoint (QStringList fields);

    PointCloudI::Ptr
    getCloud ()
    {
        return _cloud_intens;
    }

    void compute();


signals:
    /**
     * @brief emitProgress emits the percentage of progress
     * @param percentage the progress
     */
    void
    emitProgress(int percentage);

    /**
     * @brief emitCloud emits the point cloud
     * @param cloud the cloud
     */
    void
    emitCloud(PointCloudI::Ptr cloud, bool = false);

    /**
     * @brief emitQString emits A QString
     * @param str the emitted String
     * @param firstLine set true if you want to print a line above str
     * @param secondLine set true if you want to print a line below str
     */
    void
    emitQString(QString str = "", bool firstLine = false, bool secondLine = false);
};

#endif // IMPORTPCD_H
