#ifndef VOXELGRIDFILTER_H
#define VOXELGRIDFILTER_H


#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <pcl/common/common.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/common/common.h>
#include <pcl/point_types.h>
#include <pcl/octree/octree.h>
#include <pcl/filters/extract_indices.h>

#include <QString>


typedef pcl::PointXYZRGBA PointD;
typedef pcl::PointCloud<PointD> PointCloudD;
typedef pcl::PointXYZINormal PointI;
typedef pcl::PointCloud<PointI> PointCloudI;

class VoxelGridFilter
{

private:
    boost::shared_ptr<PointCloudI> input;
    boost::shared_ptr<PointCloudI> output;

    int input_size = 0;
    int output_size = 0;

    QString result_string;

    float cell_size;
    float split_size;

    boost::shared_ptr<PointCloudI>
    extractSubCloud(PointI min, PointI max,pcl::octree::OctreePointCloudSearch<PointI> & octree );

    boost::shared_ptr<PointCloudI>
    down_sample(boost::shared_ptr<PointCloudI> cloud);


public:
    VoxelGridFilter(float cell_size = 0.025f, float split_size = 1.0f);

    void
    setInput(boost::shared_ptr<PointCloudI> input_cloud);

    boost::shared_ptr<PointCloudI>
    getInput();



    boost::shared_ptr<PointCloudI>
    getOutput();

    void
    voxel_grid_filter();


};

#endif // VOXELGRIDFILTER_H
