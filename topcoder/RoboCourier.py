

"""

class RoboCourier:
    dx = [-1,0,1,1,0,-1]
    dy = [1,1,0,-1,-1,0]
    def timeToDeliver(self, path):
        cur_dir = 0 #initially facing up
        cur_x,cur_y = 0,0
        old_x,old_y = 0,0
        cells = set()
        cells.add((0,0))
        edges = set()
        for p in path:
            for mv in p:
                if mv=='L':
                    cur_dir = (cur_dir+5)%6
                elif mv=='R':
                    cur_dir = (cur_dir+1)%6
                else:
                    old_x,old_y = cur_x,cur_y
                    cur_x += self.dx[cur_dir]
                    cur_y += self.dy[cur_dir]
                    cells.add((cur_x,cur_y))
                    edges.add((old_x,old_y,cur_x,cur_y))
                    edges.add((cur_x,cur_y,old_x,old_y))
        #print edges
        shortest = {}
        for cell in cells:
            for i in xrange(6):
                shortest[cell,i] = float('inf')

        visited = set()
        shortest[(0,0),0] = 0
        while True:
            for i in xrange(6):
                if ((cur_x,cur_y),i) in visited:
                    return min([shortest[(cur_x,cur_y),i] for i in xrange(6)])
            m = float('inf')
            best_cell_dir = None
            for cell in cells:
                for i in xrange(6):
                    if (cell,i) in visited:
                        continue
                    if shortest[cell,i] < m:
                        m = shortest[cell,i]
                        best_cell_dir = (cell,i)
            ((x,y),cur_dir) = best_cell_dir
            #print best_cell_dir,shortest[best_cell_dir]
            visited.add(best_cell_dir)
            for i in range(1,6):
                j = i
                if j==4:
                    j=2
                if j==5:
                    j=1
                shortest[(x,y),(cur_dir+i)%6] = min(shortest[(x,y),(cur_dir+i)%6],shortest[(x,y),cur_dir]+3*j)
            old_x,old_y = x,y
            nx,ny = x+self.dx[cur_dir],y+self.dy[cur_dir]
            step = 1
            while (old_x,old_y,nx,ny) in edges:
                #print nx,ny,cur_dir

                shortest[(nx,ny),cur_dir] = min(shortest[(nx,ny),cur_dir], \
                                                shortest[(x,y),cur_dir]+
                                                (4 if step==1 else 2*(step-2)+8))
                step += 1
                old_x,old_y = nx,ny
                nx,ny = nx+self.dx[cur_dir],ny+self.dy[cur_dir]
"""
