/*
 * fxGtkList.cpp
 *
 *  Created on: 14 kwi 2018
 *      Author: SF
 */

#include "fxGtkList.hpp"

FxGtkList::FxGtkList()
{
  //Create the Tree model:
  treeModel = Gtk::ListStore::create(columnsModel);
  set_model(treeModel);

  //dummy pointer to controller
//  std::unique_ptr<DummyController> dummyController(new DummyController(0, NULL));

  //Fill the TreeView's model
//  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
//  row[m_Columns.idColumn] = 1;
//  row[m_Columns.nameColumna] = "right-click on this";
//  row[m_Columns.fxColumn] = std::shared_ptr<SimpleOverdriveFx>(new SimpleOverdriveFx(dummyController.get()));
//
//  row = *(m_refTreeModel->append());
//  row[m_Columns.idColumn] = 2;
//  row[m_Columns.nameColumna] = "or this";
//  row[m_Columns.fxColumn] = std::shared_ptr<SimpleOverdriveFx>(new SimpleOverdriveFx(dummyController.get()));
//
//  row = *(m_refTreeModel->append());
//  row[m_Columns.idColumn] = 3;
//  row[m_Columns.nameColumna] = "or this, for a popup context menu";
//  row[m_Columns.fxColumn] = std::shared_ptr<SimpleOverdriveFx>(new SimpleOverdriveFx(dummyController.get()));

  //Add the TreeView's view columns:
  append_column("ID", columnsModel.idColumn);
  append_column("Name", columnsModel.nameColumna);

  /*
   * dostep do danych z kolumny
   * path -> 0
   * path -> 0:1  rodzic 0, dziecko 1 itd...
   */
//  auto it = treeModel->get_iter("0");
//  int id = (*it)[columnsModel.idColumn];
//  std::cout << "  Selected ID=" << id << std::endl;
//
//  typedef Gtk::TreeModel::Children type_children; //minimise code length.
//  type_children children = treeModel->children();


  /*
   * select row
   */
//  Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = get_selection();
//  refTreeSelection->select(it);


  //Fill popup menu:
  auto item = Gtk::manage(new Gtk::MenuItem("_Edit", true));
  item->signal_activate().connect(
    sigc::mem_fun(*this, &FxGtkList::on_menu_file_popup_generic) );
  menuPopup.append(*item);

  item = Gtk::manage(new Gtk::MenuItem("_Process", true));
  item->signal_activate().connect(
    sigc::mem_fun(*this, &FxGtkList::on_menu_file_popup_generic) );
  menuPopup.append(*item);

  item = Gtk::manage(new Gtk::MenuItem("_Remove", true));
  item->signal_activate().connect(
    sigc::mem_fun(*this, &FxGtkList::on_menu_file_popup_generic) );
  menuPopup.append(*item);

  menuPopup.accelerate(*this);
  menuPopup.show_all(); //Show all menu items when the menu pops up
}

FxGtkList::~FxGtkList()
{
}

bool FxGtkList::on_button_press_event(GdkEventButton* button_event)
{
  bool return_value = false;

  //Call base class, to allow normal handling,
  //such as allowing the row to be selected by the right-click:
  return_value = TreeView::on_button_press_event(button_event);

  //Then do our custom stuff:
  if( (button_event->type == GDK_BUTTON_PRESS) && (button_event->button == 3) )
  {
    menuPopup.popup_at_pointer((GdkEvent*)button_event);

    // Menu::popup_at_pointer() is new in gtkmm 3.22.
    // If you have an older revision, try this:
    //m_Menu_Popup.popup(button_event->button, button_event->time);
  }

  return return_value;
}

void FxGtkList::on_menu_file_popup_generic()
{
  std::cout << "A popup menu item was selected." << std::endl;

  auto refSelection = get_selection();
  if(refSelection)
  {
    Gtk::TreeModel::iterator iter = refSelection->get_selected();
    if(iter)
    {
      int id = (*iter)[columnsModel.idColumn];
      std::cout << "  Selected ID=" << id << std::endl;
    }
  }
}


