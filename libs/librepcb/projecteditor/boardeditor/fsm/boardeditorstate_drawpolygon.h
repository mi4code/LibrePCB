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

#ifndef LIBREPCB_PROJECTEDITOR_BOARDEDITORSTATE_DRAWPOLYGON_H
#define LIBREPCB_PROJECTEDITOR_BOARDEDITORSTATE_DRAWPOLYGON_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "boardeditorstate.h"

#include <librepcb/common/geometry/polygon.h>
#include <librepcb/common/graphics/graphicslayername.h>

#include <QtCore>
#include <QtWidgets>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class CmdPolygonEdit;
class GraphicsLayerComboBox;
class UnsignedLengthEdit;

namespace project {

class BI_Polygon;

namespace editor {

/*******************************************************************************
 *  Class BoardEditorState_DrawPolygon
 ******************************************************************************/

/**
 * @brief The "draw polygon" state/tool of the board editor
 */
class BoardEditorState_DrawPolygon final : public BoardEditorState {
  Q_OBJECT

public:
  // Constructors / Destructor
  BoardEditorState_DrawPolygon() = delete;
  BoardEditorState_DrawPolygon(const BoardEditorState_DrawPolygon& other) =
      delete;
  explicit BoardEditorState_DrawPolygon(const Context& context) noexcept;
  virtual ~BoardEditorState_DrawPolygon() noexcept;

  // General Methods
  virtual bool entry() noexcept override;
  virtual bool exit() noexcept override;

  // Event Handlers
  virtual bool processAbortCommand() noexcept override;
  virtual bool processGraphicsSceneMouseMoved(
      QGraphicsSceneMouseEvent& e) noexcept override;
  virtual bool processGraphicsSceneLeftMouseButtonPressed(
      QGraphicsSceneMouseEvent& e) noexcept override;
  virtual bool processGraphicsSceneLeftMouseButtonDoubleClicked(
      QGraphicsSceneMouseEvent& e) noexcept override;
  virtual bool processGraphicsSceneRightMouseButtonReleased(
      QGraphicsSceneMouseEvent& e) noexcept override;
  virtual bool processSwitchToBoard(int index) noexcept override;

  // Operator Overloadings
  BoardEditorState_DrawPolygon& operator=(
      const BoardEditorState_DrawPolygon& rhs) = delete;

private:  // Methods
  bool startAddPolygon(Board& board, const Point& pos) noexcept;
  bool addSegment(const Point& pos) noexcept;
  bool updateLastVertexPosition(const Point& pos) noexcept;
  bool abortCommand(bool showErrMsgBox) noexcept;
  void layerComboBoxLayerChanged(const GraphicsLayerName& layerName) noexcept;
  void widthEditValueChanged(const UnsignedLength& value) noexcept;
  void filledCheckBoxCheckedChanged(bool checked) noexcept;
  void makeSelectedLayerVisible() noexcept;

private:
  // State
  bool mIsUndoCmdActive;
  Polygon mLastPolygonProperties;
  Point mLastSegmentPos;

  // Information about the current polygon to place. Only valid if
  // mIsUndoCmdActive == true.
  BI_Polygon* mCurrentPolygon;
  QScopedPointer<CmdPolygonEdit> mCurrentPolygonEditCmd;

  // Widgets for the command toolbar
  QList<QAction*> mActionSeparators;
  QScopedPointer<QLabel> mLayerLabel;
  QScopedPointer<GraphicsLayerComboBox> mLayerComboBox;
  QScopedPointer<QLabel> mWidthLabel;
  QScopedPointer<UnsignedLengthEdit> mWidthEdit;
  QScopedPointer<QLabel> mFillLabel;
  QScopedPointer<QCheckBox> mFillCheckBox;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace project
}  // namespace librepcb

#endif
