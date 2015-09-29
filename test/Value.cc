// This file is part of nbind, copyright (C) 2014-2015 BusFaster Ltd.
// Released under the MIT license, see LICENSE.

#ifndef EMSCRIPTEN

#include <cstring>

#include "nbind/api.h"
#include "Coord.h"

class Value {

public:

	Value() {}

	static Coord getCoord() {
		return(Coord(1,2));
	}

	static Coord callWithCoord(nbind::cbFunction &callback, Coord a) {
		return(callback.call<Coord>(a));
	}

};

#include "nbind/BindingShort.h"

#ifdef NBIND_CLASS

NBIND_CLASS(Coord) {
	construct<unsigned int, unsigned int>();
}

NBIND_CLASS(Value) {
	construct<>();

	method(getCoord);
	method(callWithCoord);
}

#endif

#endif
