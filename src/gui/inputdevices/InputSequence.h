/*
 * Xournal++
 *
 * Base class for device input handling
 * This is an input sequence, like drawing a shape etc.
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

#include <gtk/gtk.h>

class NewGtkInputDevice;

class InputSequence
{
public:
	InputSequence(NewGtkInputDevice* inputHandler);
	virtual ~InputSequence();

public:

	/**
	 * Mouse / Pen / Touch move
	 */
	void actionMoved();

	/**
	 * Mouse / Pen down / touch start
	 */
	void actionStart();

	/**
	 * Mouse / Pen up / touch end
	 */
	void actionEnd();

	/**
	 * Set current input device
	 */
	void setDevice(GdkDevice* device);


	/**
	 * Clear the last stored axes
	 */
	void clearAxes();

	/**
	 * Set the axes
	 *
	 * @param axes Will be handed over, and freed by InputSequence
	 */
	void setAxes(gdouble* axes);

	/**
	 * Copy axes from event
	 */
	void copyAxes(GdkEvent* event);

	/**
	 * Set Position
	 */
	void setCurrentPosition(double x, double y);

public:
	/**
	 * Free an input sequence, used as callback for GTK
	 */
	static void free(InputSequence* sequence);

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * Input Handler
	 */
	NewGtkInputDevice* inputHandler;

	/**
	 * Current input device
	 */
	GdkDevice* device;

	/**
	 * Axes of the input
	 */
	gdouble* axes;

	/**
	 * Position X
	 */
	double x;

	/**
	 * Position Y
	 */
	double y;
};
