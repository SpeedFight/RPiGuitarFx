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

class FxGtkList : public Gtk::TreeView
{
public:
	FxGtkList();
  virtual ~FxGtkList();

protected:
  // Override Signal handler:
  // Alternatively, use signal_button_press_event().connect_notify()
  bool on_button_press_event(GdkEventButton* button_event) override;

  //Signal handler for popup menu items:
  void on_menu_file_popup_generic();


  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); }

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
  };

  ModelColumns m_Columns;

  //The Tree model:
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  Gtk::Menu m_Menu_Popup;
};



#endif /* FXGTKLIST_HPP_ */
