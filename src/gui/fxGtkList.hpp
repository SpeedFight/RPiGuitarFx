/*
 * fxGtkList.hpp
 *
 *  Created on: 14 kwi 2018
 *      Author: SF
 */

#ifndef FXGTKLIST_HPP_
#define FXGTKLIST_HPP_

#include "config.hpp"
#include <gtkmm.h>
//#include "effectsList.hpp"
//#include "effect.hpp"
//#include "dummyController.hpp"
#include <cstddef>

class FxGtkList : public Gtk::TreeView
{
public:
	FxGtkList();
  virtual ~FxGtkList();




  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(idColumn); add(nameColumn);}

    Gtk::TreeModelColumn<unsigned int> idColumn;
    Gtk::TreeModelColumn<Glib::ustring> nameColumn;
    //Gtk::TreeModelColumn<std::shared_ptr<IFX>> fxColumn;
  };

  ModelColumns columnsModel;

  //The Tree model:
  Glib::RefPtr<Gtk::ListStore> treeModel;

  Gtk::Menu menuPopup;

  protected:
    // Override Signal handler:
    // Alternatively, use signal_button_press_event().connect_notify()
    bool on_button_press_event(GdkEventButton* button_event) override;

    //Signal handler for popup menu items:
    void on_menu_file_popup_generic();
};



#endif /* FXGTKLIST_HPP_ */
