

// check in rectangle
int checkRectX(Point p1, Point p2) {
	// find point have y min and max
	Point pMinY = p1, pMaxY = p2;
	if (p1.y > p2.y) {
		pMinY = p2;
		pMaxY = p1;
	}
	for (int y = pMinY.y + 1; y < pMaxY.y; y++) {
		// check three line
		if (checkLineX(pMinY.y, y, pMinY.x)
		 && checkLineY(pMinY.x, pMaxY.x, y)
		 && checkLineX(y, pMaxY.y, pMaxY.x)){

			cout << ("Rect x");
			cout << ("(" + pMinY.x + "," + pMinY.y + ") -> ("
					+ pMinY.x + "," + y + ") -> (" + pMaxY.x + "," + y
					+ ") -> (" + pMaxY.x + "," + pMaxY.y + ")");
			// if three line is true return column y
			return y;
		}
	}
	// have a line in three line not true then return -1
	return -1;
}

int checkRectY(Point p1, Point p2) {
	// find point have y min
	Point pMinX = p1, pMaxX = p2;
	if (p1.x > p2.x) {
		pMinX = p2;
		pMaxX = p1;
	}
	// find line and y begin
	for (int x = pMinX.x + 1; x < pMaxX.x; x++) {
		if (checkLineY(pMinX.x, x, pMinX.y)
		 && checkLineX(pMinX.y, pMaxX.y, x)
		 && checkLineY(x, pMaxX.x, pMaxX.y)) {

			cout << ("Rect y");
			cout << ("(" + pMinX.x + "," + pMinX.y + ") -> (" + x
					+ "," + pMinX.y + ") -> (" + x + "," + pMaxX.y
					+ ") -> (" + pMaxX.x + "," + pMaxX.y + ")");
			return x;
		}
	}
	return -1;
}

int checkMoreLineX(Point p1, Point p2, int type) {
	// find point have y min
	Point pMinY = p1, pMaxY = p2;
	if (p1.y > p2.y) {
		pMinY = p2;
		pMaxY = p1;
	}
	// find line and y begin
	int y = pMaxY.y;
	int row = pMinY.x;
	if (type == -1) {
		y = pMinY.y;
		row = pMaxY.x;
	}
	// check more
	if (checkLineX(pMinY.y, pMaxY.y, row)) {
		while (matrix[pMinY.x][y] != barrier && matrix[pMaxY.x][y] != barrier) {
			if (checkLineY(pMinY.x, pMaxY.x, y)) {

				cout << ("TH X " + type);
				cout << ("(" + pMinY.x + "," + pMinY.y + ") -> ("
						+ pMinY.x + "," + y + ") -> (" + pMaxY.x + "," + y
						+ ") -> (" + pMaxY.x + "," + pMaxY.y + ")");
				return y;
			}
			y += type;
		}
	}
	return -1;
}

int checkMoreLineY(Board B, Point p1, Point p2, int type) {
	Point pMinX = p1, pMaxX = p2;
	if (p1.x > p2.x) {
		pMinX = p2;
		pMaxX = p1;
	}
	int x = pMaxX.x;
	int col = pMinX.y;
	if (type == -1) {
		x = pMinX.x;
		col = pMaxX.y;
	}
	if (checkLineY(pMinX.x, pMaxX.x, col)) {
		while (B.grid[x][pMinX.y] != barrier
				&& matrix[x][pMaxX.x] != barrier) {
			if (checkLineX(pMinX.y, pMaxX.y, x)) {
				cout << ("TH Y " + type);
				cout << ("(" + pMinX.x + "," + pMinX.y + ") -> ("
						+ x + "," + pMinX.y + ") -> (" + x + "," + pMaxX.y
						+ ") -> (" + pMaxX.x + "," + pMaxX.y + ")");
				return x;
			}
			x += type;
		}
	}
	return -1;
}

MyLine checkTwoPoint(Point p1, Point p2) {
	// check line with x
	if (p1.x == p2.x) {
		if (checkLineX(p1.y, p2.y, p1.x)) {
			return new MyLine(p1, p2);
		}
	}
	// check line with y
	if (p1.y == p2.y) {
		if (checkLineY(p1.x, p2.x, p1.y)) {
			return new MyLine(p1, p2);
		}
	}

	int t = -1; // t is column find

	// check in rectangle with x
	if ((t = checkRectX(p1, p2)) != -1) {
		return new MyLine(new Point(p1.x, t), new Point(p2.x, t));
	}

	// check in rectangle with y
	if ((t = checkRectY(p1, p2)) != -1) {
		return new MyLine(new Point(t, p1.y), new Point(t, p2.y));
	}
	// check more right
	if ((t = checkMoreLineX(p1, p2, 1)) != -1) {
		return new MyLine(new Point(p1.x, t), new Point(p2.x, t));
	}
	// check more left
	if ((t = checkMoreLineX(p1, p2, -1)) != -1) {
		return new MyLine(new Point(p1.x, t), new Point(p2.x, t));
	}
	// check more down
	if ((t = checkMoreLineY(p1, p2, 1)) != -1) {
		return new MyLine(new Point(t, p1.y), new Point(t, p2.y));
	}
	// check more up
	if ((t = checkMoreLineY(p1, p2, -1)) != -1) {
		return new MyLine(new Point(t, p1.y), new Point(t, p2.y));
	}
	return null;
}
}