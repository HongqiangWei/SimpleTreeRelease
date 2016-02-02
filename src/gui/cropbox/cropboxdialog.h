#ifndef CROPBOXDIALOG_H
#define CROPBOXDIALOG_H

#include <QDialog>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/common/common.h>
#include "../pclviewer.h"

#include "../../../build/ui_crop_box_dialog.h"
#include "../../pointclouds/allignpointcloud.h"

#include "../../../src/gui/guisubclass.h"

#include <QDir>
#include <QDialog>

class CropBoxDialog : public QDialog, public GuiSubClass
{
    Q_OBJECT
public:
    /** \brief Default contrstructor
     * \param parent: The parent QT class (main UI class)
     * */
    explicit CropBoxDialog(QWidget *parent = 0);

    /** \brief connects this with the main UI class
     * \param guiPtr: the main UI class
     * */
    void
    setViewer(boost::shared_ptr<PCLViewer> guiPtr);

    /** \brief returns a shared pointer of the main UI class
     * */
    boost::shared_ptr<PCLViewer>
    getViewer();

    /** \brief connects signals and slots
     * */
    void
    init();

    /** \brief a shared pointer of the UI dialog class
     * */
    boost::shared_ptr<Ui_crop_box_dialog> dialog;

private:
    /** \brief model coefficients of the crop box
     * */
        pcl::ModelCoefficients deleteBox;

        /** \brief crop box center x
         * */
        float centerX = 0;
        /** \brief crop box center y
         * */
        float centerY = 0;
        /** \brief crop box center z
         * */
        float centerZ = 0;

        /** \brief a weak pointer to the main UI class
         * */
        boost::weak_ptr<PCLViewer> viewer;

        /** \brief adds the crop box to the visualizer
         * */
        void
        addCube();

signals:

public slots:

        /** \brief sets the crop box center x
         * \param x: the x-coordinate
         * */
    void
    set_crop_box_x ( double x ) ;

    /** \brief sets the crop box center y
     * \param y: the y-coordinate
     * */
    void
    set_crop_box_y ( double y );

    /** \brief sets the crop box center z
     * \param z: the z-coordinate
     * */
    void
    set_crop_box_z ( double z ) ;


    /** \brief sets the crop box  x-size
     * \param x: the x-size
     * */
    void
    set_crop_box_x_length ( double x );

    /** \brief sets the crop box  y-size
     * \param y: the y-size
     * */
    void
    set_crop_box_y_length ( double y ) ;

    /** \brief sets the crop box  z-size
     * \param z: the z-size
     * */
    void
    set_crop_box_z_length ( double z ) ;

    /** \brief deletes inside the crop box all points from the point cloud stored in controller class
     * */
    void
    compute_crop_box () ;


    /** \brief cancels the dialog
     * */
    void
    abort_crop_box () ;



};

#endif // CROPBOXDIALOG_H
