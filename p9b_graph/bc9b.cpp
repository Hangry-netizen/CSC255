void dGraph::printIt() const {
    int r, c;

    cout << "Graph info:\n";
    cout << "  Graph size = " << sizeV() << endl;
    cout << "  vCount = " << sizeUsedV() << endl;
    cout << "  eCount = " << sizeE() << endl;
    cout << "\nGraph contents:\n";
    for (r = 0; r < sizeUsedV(); r++) {
	cout << "  Node(" << r << "," << labels[r] << "):";
	for (c = 0; c < sizeUsedV(); c++) {
	    cout << " " << a[ind(r,c)];
	}
	cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (r = 0; r < sizeUsedV(); r++) {
	cout << "  Node(" << r << "," << labels[r] << "):";
	cout << " " << inDegree(labels[r]) << ", " << outDegree(labels[r]) << endl;
    }
}
