class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        def flood(image, i, j, orig, new):
            m, n = len(image), len(image[0])
            if i < 0 or i >= m or j < 0 or j >= n:
                return
            if image[i][j] == new:
                return

            if image[i][j] == orig:
                image[i][j] = new

                flood(image, i+1, j, orig, new)
                flood(image, i, j+1, orig, new)
                flood(image, i-1, j, orig, new)
                flood(image, i, j-1, orig, new)

                
        orig = image[sr][sc]
        flood(image, sr, sc, orig, color)

        return image