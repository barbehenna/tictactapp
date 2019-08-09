make:
	mkdir _build && cd _build && cmake .. && make && cd ..

clean:
	rm -r bin lib _build