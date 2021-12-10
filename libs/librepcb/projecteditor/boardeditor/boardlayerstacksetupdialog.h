/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBREPCB_PROJECTEDITOR_BOARDLAYERSTACKSETUPDIALOG_H
#define LIBREPCB_PROJECTEDITOR_BOARDLAYERSTACKSETUPDIALOG_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include <QtCore>
#include <QtWidgets>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class UndoStack;

namespace project {

class BoardLayerStack;

namespace editor {

namespace Ui {
class BoardLayerStackSetupDialog;
}

/*******************************************************************************
 *  Class BoardLayerStackSetupDialog
 ******************************************************************************/

/**
 * @brief The BoardLayerStackSetupDialog class
 */
class BoardLayerStackSetupDialog final : public QDialog {
  Q_OBJECT

public:
  // Constructors / Destructor
  BoardLayerStackSetupDialog() = delete;
  BoardLayerStackSetupDialog(const BoardLayerStackSetupDialog& other) = delete;
  BoardLayerStackSetupDialog(BoardLayerStack& layerStack, UndoStack& undoStack,
                             QWidget* parent) noexcept;
  ~BoardLayerStackSetupDialog() noexcept;

  // Operator Overloadings
  BoardLayerStackSetupDialog& operator=(const BoardLayerStackSetupDialog& rhs) =
      delete;

private:  // Methods
  void keyPressEvent(QKeyEvent* e);
  void accept();
  bool applyChanges() noexcept;

private:  // Data
  BoardLayerStack& mLayerStack;
  UndoStack& mUndoStack;
  QScopedPointer<Ui::BoardLayerStackSetupDialog> mUi;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace project
}  // namespace librepcb

#endif
